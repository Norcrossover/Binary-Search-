#include "tree.h"



Tree::Tree() : root(nullptr), size(0) {}



void Tree::initTree(const char * fileName) {
	char stringBuffer[MAX_SIZE];
	int intBuffer = 0;
	std::ifstream inputFile;
	inputFile.open(fileName);

	if (inputFile.good()) {
		while (!inputFile.eof()) {
			Object * object = new Object();
			// string
			inputFile.getline(stringBuffer, MAX_SIZE, ',');
			object->setString(stringBuffer);

			// int val
			inputFile >> intBuffer;
			object->setNumber(intBuffer);

			// add the objectect to the tree
			add(object);
			size++;
		}
	}	
}



Tree::~Tree() {
	destroy(root);
}




bool Tree::retrieve(const char * key, Object *& object) const {
	if (root) {
		return retrieve(key, root, object);
	}
	return false;
}



bool Tree::retrieve(const char * key, Node * curr, Object *& object) const {
	if (curr) {
		int compare  = strcmp(key, curr->object->getString());
		if (compare==0) {
			*object = *(curr->object);
			return true;
		}
		else if (compare<0) {
			return retrieve(key, curr->left, object);
		}
		else if (compare>0) {
			return retrieve(key, curr->right, object);
		}
		else {
			return false;
		}
	}
	return false;
}



bool Tree::findObject(const char * key) {
	int idx = 0;
	Object * object = new Object();
	if (retrieve(key, object) == false) {
		std::cout << std::endl << key << " could not be found." << std::endl << std::endl;
		return false;
	}
	else {
		std::cout << std::endl << std::endl;
		std::cout << "\t\tData found from " << key << std::endl << std::endl;
		object->display();
		if (object) delete object;
		return true;
	}
}



<<<<<<< HEAD
bool Tree::display(std::ostream& out) {
	int input;
	std::cout << "Choose which format to display the Tree: " << std::endl;
	std::cout << "0. Go Back" << std::endl;
	std::cout << "1. Display Inorder" << std::endl;
	std::cout << "2. Display Preorder" << std::endl;
	std::cout << "Enter Number: ";
	std::cin >> input;
        if (input == 0) return true;
	else if (input == 1) {
		displayInorder(out, root, index);
		return true;
	}
	/*
	else if (input == 2) {
		display(std::ostream& out, Node * currRoot);
		return true;
	}
	*/
	else {
		std::cout << "Invalid Option, returning to main menu..." << std::endl;
	}
	std::endl << std::endl;
	return false;
}



void Tree::displayInorder(std::ostream& out, Node * currRoot, int& index) const {
	if (currRoot) {
		displayInorder(out, currRoot->left, index);
		std::out << index << "." << std::endl;
		currRoot->object->display();
		std::out << std::endl;
		displayInorder(std::out, currRoot->right, index);
	}
}



/*
void display(std::ostream& out, Node * currRoot, int& index) {

}
*/



void add(Object *& newObject) {
	if (!curr) {
		curr = newObject;
	}
	else if (strcmp(data->getStr(), curr->data->getKey()) < 0) {
		add(curr->left, data);
	}
	else {
		add(curr->right, data);
	}
}







=======
void Tree::display(std::ostream& out, Node * currRoot){
>>>>>>> origin

}



void Tree::displayInorder(std::ostream& out, Node * currRoot, int& index) const {

}



void Tree::add(Object *& object) const {

}



/*
void Tree::add(const char * key, Object *& object) const {
	
}
*/