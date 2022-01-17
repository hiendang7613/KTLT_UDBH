#pragma once
#include <map>
#include "Product.h"

class ProductList
{
public:
	map<Product, int> list;


	void Update(Product& product, int n);

	void Remove(Product& product, int n);



};

