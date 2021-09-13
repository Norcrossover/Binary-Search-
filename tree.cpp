#include "tree.h"



Tree::Tree() : root(nullptr), size(0) {}



Tree::Tree(const char * fileName) {
	initTree(fileName);
}



void Tree::initTree(const char * fileName) {
	char stringBuffer[MAX_SIZE];
	int intBuffer = 0;
	std::ifstream inputFile;
	inputFile.open(fileName);

	if (inputFile.good()) {
		while (!inputFile.eof()) {
			Object * object = new Object();
			std::cout << "delegated memory for object succesfully" << std::endl;
			// string
			inputFile.getline(stringBuffer, MAX_SIZE, ';');
			std::cout << stringBuffer << std::endl;
			object->setString(stringBuffer);
			std::cout << object->getString() << std::endl;

			// int val
			inputFile >> intBuffer;
			object->setNumber(intBuffer);
			std::cout << object->getNumber() << std::endl;

			// add the objectect to the tree
			add(object);
			std::cout << "succesfully added object" << std::endl;
			size++;
		}
	}	
	else {
	std::cerr << "Could not open file! Program Ending" << std::endl;
	exit(1);
	}
}



Tree::~Tree() {
	destroy(root);
}




void Tree::destroy(Node *& currRoot) {
	if (currRoot) {
		// recurse through the tree
		destroy(currRoot->left);
		destroy(currRoot->right);
		// delete the current node (first being a leaf node) and set it to nullptr
	        delete currRoot;
		currRoot = nullptr;
	}
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



bool Tree::display(std::ostream& out) {
	int input, index = 0;
	char buffer[MAX_SIZE];
	std::cout << "\t";
	std::cout << "Choose which format to display the Tree: " << std::endl;
	std::cout << "\t";
	std::cout << "0. Go Back" << std::endl;
	std::cout << "\t";
	std::cout << "1. Display Inorder" << std::endl;
	std::cout << "\t";
	std::cout << "2. Display Preorder" << std::endl;
	std::cin.getline(buffer, MAX_SIZE, '\n');
	std::cout << "\t";
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
	out << std::endl << std::endl;
	
	return false;
}



void Tree::displayInorder(std::ostream& out, Node * currRoot, int& index) const {
	if (currRoot) {
		displayInorder(out, currRoot->left, index);
		out << index << "." << std::endl;
		currRoot->object->display();
		out << std::endl;
		index++;
		displayInorder(out, currRoot->right, index);
	}
}




void Tree::add(Object *& newObject) {
	add(this->root, newObject);
}



void Tree::add(Node *& curr, Object *& newObject) {
	if (!curr) {
		//curr->object = newObject;
		curr = new Node(newObject);
	}
	else if (strcmp(newObject->getString(), curr->object->getString()) < 0) {
		add(curr->left, newObject);
	}
	else {
		add(curr->right, newObject);
	}
}



bool Tree::removeKey(const char * key) {
	return removeKey(this->root, key);
}



bool Tree::removeKey(Node *& curr, const char * key) {
	if (!curr) return false;
	int found = strcmp(curr->object->getString(), key);
	if (found == 0) {
		deleteNode(curr);
		return true;
	} 
	else if (found > 0) {
		return removeKey(curr->left, key);
	}
	else {
		return removeKey(curr->right, key);
	}
}



// case 1: leaf node deletion (no children)
// case 2: only child on right
// case 3: only child on left
// case 4: two children
void Tree::deleteNode(Node *& target) {
	if ((target->right == nullptr) && (target->left == nullptr)) {
		delete target;
		target = nullptr;
	}
	else if (target->right != nullptr) {
		Node * temp = target;
		target = target->left;
		delete target;
	}
	else if (target->left != nullptr) {
		Node * temp = target;
		target = target->right;
		delete target;
	}
	else {
		Node * prev = nullptr;
		Node * curr = target->right;
		if (curr->left != nullptr) {
			target->right = curr->right;
		}
		else {
			while (curr->left) {
				prev = curr;
				curr = curr->left;
			}
			prev->left = curr->right;
		}
		delete target->object;
		target->object = curr->object;
		delete curr;
	}	
}


/*
int Tree::getHeightNode() {
	
	return 0;
}



int Tree::getHeightEdge() {

	return -1;

}



int Tree::getMaxObject() {
	return 0;
}



int Tree::getMinObject() {

	return min;
}

*/
