#include "stdafx.h"
#include "Block.h"
#include <iostream>

using namespace std;

Block::Block() {
	cout << "CTOR Block @" << this << endl;
	this->value = 0;
	this->data = "(nodata)";
}

Block::Block(const Block& other) {
	cout << "CCTor Block @" << this << endl;
	this->value = other.value;
	this->data = other.data;
}

Block::~Block() noexcept {
	cout << "DTOR Block @" << this << endl;
}

Block& Block::operator=(const Block& other) {
	cout << "Assignment opr Block @" << this << endl;

	if (this != &other) {
		this->value = other.value;
		this->data = other.data;
	}

	return *this;
}

Block& Block::operator=(const Block&& other) {
	cout << "Move Assignment opr Block @" << this << endl;

	if (this != &other) {
		this->value = other.value;
		this->data = other.data;
	}

	return *this;
}

void Block::setup(int value) {
	this->value = value;
	this->data = "The value is " + to_string(value);
}

Block Block::operator+(const Block& other) const {
	Block b = Block();
	b.value = this->value + other.value;
	b.data = this->data + other.data;
	return b;
}

ostream& operator<<(ostream& os, const Block& block) {
	os << "Block @" << &block << " data: '" << block.data << "' value: " << block.value;
	return os;
}

#ifdef MOVESEMANTICS

// move-constructor
Block::Block(Block&& other) noexcept {
	cout << "MCTOR Block " << this << endl;
	value = std::move(other.value);
	data = std::move(other.data);

	// 'reset' 't originele object
	other.value = 0;
	other.data = "(nodata)";
}

// move-assignment operator
Block& Block::operator=(Block&& other) noexcept {
	cout << "MOVE assignment oper Block " << this << endl;

	if (this != &other) {
		this->value = std::move(other.value);
		this->data = std::move(other.data);

		// 'reset' 't originele object
		other.value = 0;
		other.data = "(nodata)";
	}

	return *this;
}


#endif