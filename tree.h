#include "obj.h"

class Tree {
	public:
		// constructor and destructor
		Tree();
		//Tree(aTree);
		void initTree(const char * fileName);
		~Tree();

		// accessors
		bool retrieve(const char * key, Object *& obj) const;
		bool displayObject(const char * key);
		int getSize() const;

		// mutators
		void add(Object *& newObject);
		bool removeKey(const char * key);
		

	private:
		struct Node {
			Node() {
				data = nullptr;
				left = right = nullptr;
			}
			Node(Object *& newObject) {
				obj = newObject;
				left = right = nullptr;
			}
			~Node() {
				if (obj) delete obj;
			}
			Object * obj;
			Node * left;
			Node * right;
		};
		Node * root;
		int size;
		
		// destructor fxns
		void destroy(Node *& currRoot);
		
		// display tree functions
	        void display(ostream& out, Node * currRoot);	
		void displayInorder(ostream& out, Node * currRoot, int& index) const;

		// Recursive fxns
		bool retrieve(const char * key, Node * currRoot, Object *& obj) const;
		bool removeKey(Node *& curr, const char * key);
};
