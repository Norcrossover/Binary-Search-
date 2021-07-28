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
		int getNumber();
		void display();
		
		// mutators
		void setString(const char * string);
		void setNumber(const int number);

	private:
		char * str;
		int num;
};
