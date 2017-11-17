#include "SmartPtr.hpp"
#include "Person.hpp"


int main(){
	SmartPtr<Person> p(new Person(20, "Scott"));
	p->Display();
	{
		SmartPtr<Person> q = p;
		q->Display();	// Destructor of q will be called after this clause.

		SmartPtr<Person> r;
		r = p;
		r->Display();	// Destructor of r will be callsed after this clause.
	}
	p->Display();	// Destructor of p will be called after this clause.

	return 0;
}
