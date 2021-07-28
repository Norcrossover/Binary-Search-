#include "tree.h"



// ---------------------------- public functions
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
			object->setStr(stringBuffer);

			// int val
			inputFile >> intBuffer;
			object->setNum(intBuffer);

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



bool Tree::retrieve(const char * key, Node * currRoot, Object *& object) const {
	if (curr) {
		int compare  = strcmp(key, curr->object->getStr());
		if (compare==0) {
			*object = curr->object;
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



bool displayObject(const char * key) {
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




