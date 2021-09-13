#include "tree.h"

int main() {

	int userInput = 0;
	const char fileName[MAX_SIZE] = "test.txt";
	Tree * tree = new Tree();
	tree->initTree(fileName);

	do {
		std::cout << "0. Quit program" << std::endl;
		std::cout << "1. Display Tree" << std::endl;
		std::cout << "2. Find Object" << std::endl;
		std::cin >> userInput;
		if (userInput == 1) {
			tree->display(std::cout);
		}
		else if (userInput == 2) {
			char buffer[MAX_SIZE];
			std::cout << "Please enter key value: ";
			std::cin.getline(buffer, MAX_SIZE, '\n');
			char * key = new char[strlen(buffer)+1];	
			tree->findObject(key);
		}
		else {
			userInput = 0;
		}
	} while (userInput != 0);

	delete tree;

	return 0;
}
