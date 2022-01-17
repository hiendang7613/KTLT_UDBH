#include <iostream>
#include "Store.h"

int main()
{
    Store store;

    //Product p("123", "halu", 15);
    //Product p2("124", "halu2", 5);
    //Product p3("126", "halu3", 34);
    //Product p4("127", "halu4", 232);

    //store.AddProduct(p);
    //store.AddProduct(p2);
    //store.AddProduct(p3);
    //store.AddProduct(p4);

    //Employee e("46", "nguyen a", "tutu", "xzx", 0);
    //Employee e2("62", "nguyen b", "tutu2", "xzy", 0);
    //Employee e3("49", "nguyen c", "tutu3", "xza", 1);

    //store.AddEmployee(e);
    //store.AddEmployee(e2);
    //store.AddEmployee(e3);

    //Bill b("xx");
    //Bill b2("xr");
    //Bill b3("xz");

    //store.AddBill(b);
    //store.AddBill(b2);
    //store.AddBill(b3);

    //store.Export("helo.bin");
    store.Import("helo.bin");
    store.Print();

    return 0;
}
