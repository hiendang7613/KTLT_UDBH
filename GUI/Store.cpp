#include "Store.h"



bool Store::IsHaveAccount(Employee& employee, bool& IsAdmin)
{
	auto x = employees.Find(employee, Employee::FindAccount);
	if (x.size() == 0) {
		return false;
	}

	IsAdmin = employees.Arr()[x[0]].GetIsManager();
	return true;
}

bool Store::IsHaveProduct(Product& product) {
	return products.Find(product, Product::CompareFunc).size() != 0;
}

bool Store::IsHaveEmployee(Employee& employee) {
	return employees.Find(employee, Employee::CompareFunc).size() != 0;
}

bool Store::IsHaveBill(Bill& bill) {
	return bills.Find(bill, Bill::CompareFunc).size() != 0;
}

bool Store::AddProduct(Product& product) {
	if (IsHaveProduct(product)) {
		return false;
	}
	products.Add(product);
	return true;
}

void Store::AddEmployee(vector<Employee>& employee)
{
	int n = employee.size();
	for (size_t i = 0; i < n; i++)
	{
		AddEmployee(employee[i]);
	}
}
void Store::AddBill(vector<Bill>& bills)
{
	int n = bills.size();
	for (size_t i = 0; i < n; i++)
	{
		AddBill(bills[i]);
	}
}
void Store::AddProduct(vector<Product>& products)
{
	int n = products.size();
	for (size_t i = 0; i < n; i++)
	{
		AddProduct(products[i]);
	}
}

bool Store::AddEmployee(Employee& employee) {
	if (IsHaveEmployee(employee)) {
		return false;
	}
	employees.Add(employee);
	return true;
}

bool Store::AddBill(Bill& bill) {
	if (IsHaveBill(bill)) {
		return false;
	}
	bills.Add(bill);
	return true;
}

bool Store::DeleteProduct(string& iD) {
	Product product(iD, "", "", 0);
	vector<int> x = products.Find(product, Product::CompareFunc);
	if (x.size() == 0) {
		return false;
	}
	products.Delete(x[0]);
	return true;
}

bool Store::DeleteEmployee(string& iD) {
	Employee employee(iD, "", "", "", 0);
	vector<int> x = employees.Find(employee, Employee::CompareFunc);
	if (x.size() == 0) {
		return false;
	}
	employees.Delete(x[0]);
	return true;

}

bool Store::DeleteBill(string& iD) {
	Bill bill(iD);
	vector<int> x = bills.Find(bill, Bill::CompareFunc);
	if (x.size() == 0) {
		return false;
	}
	bills.Delete(x[0]);
	return true;
}

bool Store::UpdateProduct(Product& product) {
	int pos = products.Find(product, Product::CompareFunc)[0];
	if (pos == -1) {
		return false;
	}
	products.Update(product, pos);
	return true;
}

bool Store::UpdateEmployee(Employee& employee) {
	int pos = employees.Find(employee, Employee::CompareFunc)[0];
	if (pos == -1) {
		return false;
	}
	employees.Update(employee, pos);
	return true;
}

bool Store::UpdateBill(Bill& bill) {
	int pos = bills.Find(bill, Bill::CompareFunc)[0];
	if (pos == -1) {
		return false;
	}
	bills.Update(bill, pos);
	return true;
}


bool Store::Import(string fileName) {
	ifstream f;
	f.open(fileName, ios::binary | ios::in);
	if (!f.good()) {
		return false;
	}

	int n;
	f >> n;
	products.NewAlloc(n);
	f.read((char*)products.Arr(), n * sizeof(Product));

	f >> n;
	employees.NewAlloc(n);
	f.read((char*)employees.Arr(), n * sizeof(Employee));

	f >> n;
	bills.NewAlloc(n);
	f.read((char*)bills.Arr(), n * sizeof(Bill));
	f.close();
	return true;
}

bool Store::Export(string fileName) {
	ofstream f;
	f.open(fileName, ios::binary | ios::out);
	if (!f.good()) {
		return false;
	}

	int n;

	n = products.N();
	f << n;
	f.write((char*)products.Arr(), n * sizeof(Product));

	n = employees.N();
	f << n;
	f.write((char*)employees.Arr(), n * sizeof(Employee));

	n = bills.N();
	f << n;
	f.write((char*)bills.Arr(), n * sizeof(Bill));
	f.close();
	return true;
}
