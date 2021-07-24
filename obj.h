#include <fstream>
#include <cstring>
#include <iostream>
const int MAX_SIZE = 256;

class Obj {
	public:
		// constructor and destructor
		Obj();
		~Obj();
	
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
