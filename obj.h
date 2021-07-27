#include <fstream>
#include <cstring>
#include <iostream>
const int MAX_SIZE = 256;

class Object {
	public:
		// constructor and destructor
		Object();
		~Object();
	
		// accessors
		char * getString();
		int getNum();
		void display();
		
		// mutators
		void setStr(const char * string);
		void setNum(const int number);

	private:
		char * str;
		int num;
};
