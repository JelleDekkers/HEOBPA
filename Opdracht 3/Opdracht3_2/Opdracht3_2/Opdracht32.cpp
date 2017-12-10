#include "stdafx.h"
#include <iostream>
#include "Parent.h"
#include <memory>

using namespace std;

int main() {

	//Parent* p1 = new Parent("Parent1");
	shared_ptr<Parent> p1 = shared_ptr<Parent>(new Parent("Parent1"));
	cout << "P1:" << *p1 << endl;

	cout << "p1 references: " << p1.use_count() << endl;

	//Parent* p2 = new Parent(*p1); // roept de copy constructor aan
	shared_ptr<Parent> p2 = p1;
	cout << "P2:" << *p2 << endl;

	cout << "p1 references: " << p1.use_count() << endl;

	//Parent* p3 = new Parent("Parent3");
	shared_ptr<Parent> p3 = make_shared<Parent>("Parent3");
	cout << "P3:" << *p3 << endl;

	cout << "p1 references: " << p1.use_count() << endl;

	p3 = p1; // roept de assignment operator aan
	cout << "P3:" << *p3 << endl;

	cout << "p1 references: " << p1.use_count() << endl;

	return 0;
}