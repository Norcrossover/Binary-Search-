#include "tree.h"



// ---------------------------- public functions
Tree::Tree() : root(nullptr), size(0) {}



void Tree::initTree(const char * fileName) {
	char stringBuffer[MAX_SIZE];
	int intBuffer = 0;
	ifstream = inputFile;
	inputFile.open(fileName);

	if (inputFile.good()) {
		while (!inputFile.eof()) {
			Obj * obj = new Obj();
			// string
			inputFile.getline(stringBuffer, MAX_SIZE, ',');
			obj->setStr(stringBuffer);

			// int val
			inputFile >> intBuffer;
			obj->setNum(intBuffer);

			// add the object to the tree
			add((obj);
			size++;
		}
	}	
}



void Tree:~Tree() {
	destroy(root);
}




bool Tree::retrieve(const char * key, Obj *& obj) const {
	if (root) {
		return retrieve(key, root, obj);
	}
	return false;
}



bool Tree::retrieve(const char * key, Node * currRoot, Obj *& obj) const {
	if (curr) {
		int compare  = strcmp(key, curr->obj->getStr());
		if (compare==0) {
			*obj = curr->obj;
			return true;
		}
		else if (compare<0) {
			return retrieve(key, curr->left, obj);
		}
		else if (compare>0) {
			return retrieve(key, curr->right, obj);
		}
		else {
			return false;
		}
	}
	return false;
}



bool displayObj(const char * key) {
	int idx = 0;
	Obj * obj = new Obj();
	if (retrieve(key, obj) == false) {
		cout << endl << key << " could not be found." << endl << endl;
		return false;
	}
	else {
		cout << endl << endl;
		cout << "\t\tData found from " << key << endl << endl;
		obj->display();
		if (obj) delete obj;
		return true;
	}
}




