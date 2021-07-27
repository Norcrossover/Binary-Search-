#include "obj.h"



Object::Object() {
	str = nullptr;
	num = 0;
}



Object::~Object() {
	if (str) delete str;
	str = nullptr;
	num = 0;
}



char * Object::getString() {
	return str;
}



int Object::getNum() {
	return num;
}



void Object::display() {
	cout << endl << endl;
	cout << "STRING: " << getString();
	cout << "NUM:    " << getNum();
	cout << endl << endl;
}



void Object::setStr(const char * string) {
	if (str) delete str;
	strcpy(str, string);;
}



void Object::setNum(const int number) {
	num = number;
}
