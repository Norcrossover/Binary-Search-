#include "obj.h"

class Tree {
	public:
		// constructor and destructor
		Tree();
		//Tree(aTree);
		void initTree(const char * fileName);
		~Tree();

		// accessors
		bool retrieve(const char * key, Obj *& obj) const;
		bool displayObj(const char * key);
		int getSize() const;

		// mutators
		void add(Obj *& newObj);
		bool removeKey(const char * key);
		

	private:
		struct Node {
			Node() {
				data = nullptr;
				left = right = nullptr;
			}
			Node(Obj *& newObj) {
				obj = newObj;
				left = right = nullptr;
			}
			~Node() {
				if (obj) delete obj;
			}
			Obj * obj;
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
		bool retrieve(const char * key, Node * currRoot, Obj *& obj) const;
		bool removeKey(Node *& curr, const char * key);
};
