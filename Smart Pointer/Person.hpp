#include <iostream>
using namespace std;

class Person{
private:
	int age;
	string name;
public:
	Person(): age(0), name(){}
	Person(int age, string name): age(age), name(name){}
	~Person(){}
	void Display(){
		cout << "Name is " << name << " and age is " << age << "." << endl;
	}
	void Shoot(){
		cout << "Ooooooooooooooooooo" << endl;
	}
};
