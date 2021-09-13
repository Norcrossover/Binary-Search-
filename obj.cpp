#include "obj.h"



Object::Object() {
	str = nullptr;
	num = 0;
}



Object::~Object() {
	if (str) delete [] str;
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
	std::cout << "string" << std::endl;
	if (str != nullptr) delete str;
	this->str = new char[strlen(string)+1];
	strcpy(this->str, string);
	std::cout << "this->str" << std::endl;
}



void Object::setNumber(const int number) {
	this->num = number;
}




void Object::operator=(const Object& newObject) {
	setString(newObject.str);
	setNumber(newObject.num);
}

