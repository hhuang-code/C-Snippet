#include "RefCount.hpp"

template <typename T>
class SmartPtr{
public:
	SmartPtr();
	SmartPtr(T* p);
	SmartPtr(const SmartPtr<T>& sp);
	~SmartPtr();
	T& operator*();
	T* operator->();
	SmartPtr<T>& operator=(const SmartPtr<T>& sp);
private:
	T* pData;
	RefCount* refCnt;
};

template <typename T>
SmartPtr<T>::SmartPtr(): pData(0), refCnt(0){
	refCnt = new RefCount();
	refCnt->Add();
}

template <typename T>
SmartPtr<T>::SmartPtr(T* p): pData(p), refCnt(0){
	refCnt = new RefCount();
	refCnt->Add();
}

template <typename T>
SmartPtr<T>::SmartPtr(const SmartPtr<T>& sp): pData(sp.pData), refCnt(sp.refCnt){
	refCnt->Add();
}

template <typename T>
SmartPtr<T>::~SmartPtr(){
	if(refCnt->Release() == 0){
		delete pData;
		delete refCnt;
	}
}

template <typename T>
T& SmartPtr<T>::operator*(){
	return *pData;
}

template<typename T>
T* SmartPtr<T>::operator->(){
	return pData;
}

template<typename T>
SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr<T>& sp){
	// Avoid self assignment
	if(this != &sp){
		// Decrease the old reference count and if referece becomes zero, delete the old data
		if(refCnt->Release() == 0){
			delete pData;
			delete refCnt;
		}
		// Reassign. Copy the data and reference pointer, and then increase the reference count
		pData = sp.pData;
		refCnt = sp.refCnt;
		refCnt->Add();
	}

	return *this;
}
