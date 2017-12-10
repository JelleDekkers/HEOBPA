#include "stdafx.h"
#include <iostream>
#include "Parent.h"

Parent::Parent(string name) {
	this->name = name;
	string childName = "ChildOf" + name;
	//this->child = new Child(childName);
	this->child = unique_ptr<Child>(new Child(childName));
}

Parent::Parent(const Parent& other) {
	cout << "Parent cctor" << endl;
	this->name = other.name;
	//this->child = new Child(*other.child);
	this->child = unique_ptr<Child>(new Child(*other.child));

}

Parent::~Parent() {
	cout << "destructor " << this->name << endl;
	//cout << "child: " << *(this->child) << endl; 
	//delete this->child;
}

Parent& Parent::operator=(const Parent& other) {
	cout << "Parent assignment" << endl;

	if (this == &other) {
		return *this;
	}

	this->name = other.name;
	//delete this->child;
	this->child = unique_ptr<Child>(new Child(*other.child));

	return *this;
}

ostream& operator<<(ostream& os, const Parent& parent) {
	os << "name: " << parent.name << " child: " << *parent.child;
	return os;
}

// move-constructor
Parent::Parent(Parent&& other) noexcept {
	cout << "move constructor for " << other.name << endl;
	name = std::move(other.name);
	child = std::move(other.child);

	// 'reset' 't originele object
	other.name = "";
	other.child = nullptr;
}