#include "stdafx.h"

#include <iostream>
#include "Block.h"

// dummy function that operates on the Block
Block fillBlock(Block b, int value) {
	std::cout << " parameter b " << &b << std::endl;

	b.setup(value);
	return b;

	/* LET OP: in dit volgende geval ziet de compiler dat 't al om een nieuw object gaat, en
	* wordt de move-constructor overgeslagen: bnew wordt direct in de 'otherBlock' variabele gegoten...
	Block bnew = b;
	bnew.setup(value);
	return bnew;
	*/
}

int main() {
	std::cout << "Begin" << std::endl;

	Block block;
	std::cout << " Block: " << block << std::endl;

	std::cout << "Assignment" << std::endl;
	Block otherblock = fillBlock(block, 10);

	std::cout << "Na Assignment" << std::endl;
	std::cout << " OtherBlock:" << otherblock << std::endl;

	Block block3;
	std::cout << " block3:" << block3 << std::endl;
	block3 = std::move(otherblock);
	Block block4;
	block4.setup(20);
	block3 = otherblock + block4;
	std::cout << " block3:" << block3 << std::endl;


	std::cout << "End" << std::endl;

	return 0;
}