#include "stdafx.h"
#include "Child.h"

Child::Child(string name) {
	this->name = name;
}

Child::Child(const Child& other) {
	this->name = other.name;
}

Child::~Child() {
	cout << "dstructor of " << this->name << endl;
}

ostream& operator<<(ostream& os, const Child& child) {
	os << "name: " << child.name;
	return os;
}

