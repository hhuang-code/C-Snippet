class RefCount{
public:
	RefCount(): count(0){}
	void Add(){count++;}
	int Release(){return --count;}
private:
	int count;
};
