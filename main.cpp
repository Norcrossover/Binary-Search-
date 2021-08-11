#include "tree.h"

int main() {

	int userInput = 0;
	Tree * tree = new Tree();

	do {
		std::cout << "0. Quit program" << std::endl;
		std::cout << "1. Display Tree" << std::endl;
		std::cout << "2. Find Object" << std::endl;
	} while (userInput != 0);

	return 0;
}
