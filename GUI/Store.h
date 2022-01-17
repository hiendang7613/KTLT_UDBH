#pragma once
#include "Product.h"
#include "Employee.h"
#include "Bill.h"
#include "MyList.h"
#include <vector>
#include <fstream>

class Store
{
	 MyList<Product> products;
	 MyList<Employee> employees;
	 MyList<Bill> bills;

public:

	 MyList<Product> GetProductList() {
		return products;
	}
	 MyList<Employee> GetEmployeeList() {
		return employees;
	}
	 MyList<Bill> GetBillList() {
		return bills;
	}

	 bool IsHaveAccount(Employee& employee, bool& IsAdmin);
	 bool IsHaveProduct(Product& product);
	 bool IsHaveEmployee(Employee& employee);
	 bool IsHaveBill(Bill& bill);

	 bool AddProduct(Product& product);
	 void AddProduct(vector<Product>& products);
	 bool AddEmployee(Employee& employee);
	 void AddEmployee(vector<Employee>& employee);
	 bool AddBill(Bill& bill);
	 void AddBill(vector<Bill>& bills);

	 bool DeleteProduct(string& iD);
	 bool DeleteEmployee(string& iD);
	 bool DeleteBill(string& iD);

	 bool UpdateProduct(Product& product);
	 bool UpdateEmployee(Employee& employee);
	 bool UpdateBill(Bill& bill);

	 bool Import(string fileName);
	 bool Export(string fileName);
};

