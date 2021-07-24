#include "obj.h"



Obj::Obj() {
	str = nullptr;
	num = 0;
}



Obj::~Obj() {
	if (str) delete str;
	str = nullptr;
	num = 0;
}



char * Obj::getString() {
	return str;
}



int Obj::getNum() {
	return num;
}



void Obj::display() {
	cout << endl << endl;
	cout << "STRING: " << getString();
	cout << "NUM:    " << getNum();
	cout << endl << endl;
}



void Obj::setStr(const char * string) {
	if (str) delete str;
	strcpy(str, string);;
}



void Obj::setNum(const int number) {
	num = number;
}
