#pragma once
//#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Product.h"
#include <map>
#include <ctime>

using namespace std;

struct Product_Count
{
	Product product;
	int count;
};
	
class Bill
{
	string iD;
	int totalCost;
	tm time;

	map<string, Product_Count> list;
public:

	map<string, Product_Count>* ProductList() {
		return &list;
	}
	

	void SetID(string value)
	{
		iD = value;
	}
	string GetID()
	{
		return iD;
	}

	void SetTotalCost(int value)
	{
		totalCost = value;
	}
	int GetTotalCost()
	{
		return totalCost;
	}

	void SetTime(tm value)
	{
		time = value;
	}
	tm GetTime()
	{
		return time;
	}	

	string GetTimeString()
	{
		return to_string(time.tm_mday) + "/" + to_string(time.tm_mon+1) + "/" + to_string(time.tm_year+1900);
	}


public:
	void UpdateProduct(Product& product, int n);

	bool DeleteProduct(string& iD);

	void UpdateTotal();

public:
	static bool CompareFunc(Bill& t, Bill& t2) {
		return t.iD == t2.iD;
	}
	static bool CompareFuncDate(Bill& t, Bill& t2) {
		return t.time.tm_yday == t2.time.tm_yday && t.time.tm_year == t2.time.tm_year;
	}

	Bill();

	Bill(string s);

	
	Bill(string iD, int totalCost, tm time) {
		this->iD = iD;
		this->totalCost = totalCost;
		this->time = time;
	}

	Bill(string iD, int totalCost, tm time, map<string, Product_Count> list) {
		this->iD = iD;
		this->totalCost = totalCost;
		this->time = time;
		this->list = list;
	}
};

