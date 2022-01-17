#pragma once
#include <iostream>
#include <string>

using namespace std;

class Product
{
	string iD;
	string name;
	string type;
	int cost;

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
	void SetType(string value)
	{
		type = value;
	}
	string GetType()
	{
		return type;
	}

	void SetCost(int value)
	{
		cost = value;
	}
	int GetCost()
	{
		return cost;
	}
public:

public:
	static bool CompareFunc(Product& t, Product& t2) {
		return t.iD == t2.iD;
	}

	Product();

	Product(string iD, string name, string type, int cost);

};



