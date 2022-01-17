#include "Bill.h"

void Bill::UpdateProduct(Product& product, int n)
{
	list[product.GetID()] = Product_Count{product,n} ;
	UpdateTotal();
}

bool Bill::DeleteProduct(string& iD)
{
	int i = list.erase(iD);
	UpdateTotal();
	if (i == 0) {
		return false;
	}
	return true;
}

void Bill::UpdateTotal()
{
	totalCost = 0;
	for (auto it = list.begin(); it != list.end();it++)
	{
		Product_Count x = it->second;
		int cost = x.count * x.product.GetCost();
		totalCost += cost;
	}
}

Bill::Bill() {
	time_t now = std::time(0);
	time = *localtime(&now);
}

Bill::Bill(string s) {
	iD = s;
	totalCost = 0;
	time_t now = std::time(0);
	time = *localtime(&now);
}

