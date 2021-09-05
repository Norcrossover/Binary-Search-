#include "obj.h"

class Tree {
	public:
		// constructor and destructor
		Tree();
		Tree(const char * fileName);
		//Tree(aTree);
		void initTree(const char * fileName);
		~Tree();

		// accessors
		bool retrieve(const char * key, Object *& object) const;
		bool display(std::ostream & out);
		bool findObject(const char * key);
		int getSize() const;
		int getHeightNode();
		int getHeightEdge();
		int getMaxObject();
		int getMinObject();

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
// may delete    		void display(std::ostream& out, Node * currRoot);	
		void displayInorder(std::ostream& out, Node * currRoot, int& index) const;

		// Recursive fxns
		void add(Node *& curr, Object *& newObject);
		bool retrieve(const char * key, Node * currRoot, Object *& object) const;
		bool removeKey(Node *& curr, const char * key);
		void deleteNode(Node *& target);
};
