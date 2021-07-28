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



int Object::getNumber() {
	return num;
}



void Object::display() {
	std::cout << std::endl << std::endl;
	std::cout << "STRING: " << getString();
	std::cout << "NUM:    " << getNumber();
	std::cout << std::endl << std::endl;
}



void Object::setString(const char * string) {
	if (str) delete str;
	strcpy(str, string);;
}



void Object::setNumber(const int number) {
	num = number;
}




void Object::operator=(Const Object& newObject) {
	setString(newObject.getString());
	setNumber(newObject.getNumber());
}

