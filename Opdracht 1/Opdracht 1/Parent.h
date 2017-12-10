#pragma once

#include "stdafx.h"
#include <string>
#include <ostream>
#include "Child.h"
#include <memory>

using namespace std;

class Parent {
public:
	Parent(string name);

	// copy constructor
	Parent(const Parent& other);

	// deconstructor
	virtual ~Parent();

	// copy operator
	Parent& operator=(const Parent& other);

	// move-constructor
	Parent(Parent&& other) noexcept;

	friend ostream& operator<<(ostream& os, const Parent& parent);

private:
	string name;
	//Child* child;
	unique_ptr<Child> child;
};
