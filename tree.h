#include "obj.h"

class Tree {
	public:
		// constructor and destructor
		Tree();
		//Tree(aTree);
		void initTree(const char * fileName);
		~Tree();

		// accessors
		bool retrieve(const char * key, Object *& object) const;
		bool display(std::ostream & out);
		bool findObject(const char * key);
		int getSize() const;

		// mutators
		void add(Object *& newObject);
		bool removeKey(const char * key);
		

	private:
		struct Node {
			Node() {
				object = nullptr;
				left = right = nullptr;
			}
			Node(Object *& newObject) {
				object = newObject;
				left = right = nullptr;
			}
			~Node() {
				if (object) delete object;
			}
			Object * object;
			Node * left;
			Node * right;
		};
		Node * root;
		int size;
		
		// destructor fxns
		void destroy(Node *& currRoot);
		
		// display tree functions
//    		void display(std::ostream& out, Node * currRoot);	
		void displayInorder(std::ostream& out, Node * currRoot, int& index) const;

		// Recursive fxns
		bool retrieve(const char * key, Node * currRoot, Object *& object) const;
		bool removeKey(Node *& curr, const char * key);
};
