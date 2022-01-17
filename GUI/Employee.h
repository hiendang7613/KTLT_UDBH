#pragma once
#include <iostream>
#include <string>

using namespace std;

class Employee
{
	string iD;
	string name;
	string username;
	string password;
	bool isManager;

public:

	void SetID(string value)
	{
		iD = value;
	}
	string GetID()
	{
		return iD;
	}

	void SetName(string value)
	{
		name = value;
	}
	string GetName()
	{
		return name;
	}

	void SetUsername(string value)
	{
		username = value;
	}
	string GetUsername()
	{
		return username;
	}

	void SetPassword(string value)
	{
		password = value;
	}
	string GetPassword()
	{
		return password;
	}

	void SetIsManager(bool value)
	{
		isManager = value;
	}
	bool GetIsManager()
	{
		return isManager;
	}

public:
	static bool CompareFunc(Employee& t, Employee& t2) {
		return t.iD == t2.iD;
	}

	static bool FindAccount(Employee& t, Employee& t2) {
		return t.username == t2.username && t.password == t2.password;
	}


public:
	Employee() {

	}

	Employee(string iD, string name, string username, string password, bool isManager);

};

