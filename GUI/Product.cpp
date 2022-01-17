#include "Product.h"

Product::Product() {
}

Product::Product(string iD, string name, string type, int cost) {
	this->iD = iD;
	this->name = name;
	this->type = type;
	this->cost = cost;
}
