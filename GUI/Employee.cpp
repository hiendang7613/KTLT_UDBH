#include "Employee.h"

Employee::Employee(string iD, string name, string username, string password, bool isManager) {
	this->iD = iD;
	this->name = name;
	this->username = username;
	this->password = password;
	this->isManager = isManager;
}
