#include "Product.h"
#include "lib.h"



int GeneralProduct::getId() const
{
    return id;
}
string GeneralProduct::getName() const 
{ 
    return name;
}
double GeneralProduct::getPrice() const 
{
    return price; 
}
string GeneralProduct::getQuantity() const 
{
    return quantity;
}

void GeneralProduct::display() const {
    cout << "  " << id << "\t     " << name << "\t" << price << " Hrivnas " << "\t" << quantity << endl;
}

void displayProducts(const vector<shared_ptr<Product>>& products) {
    cout << "-----------------------------------------------------------" << endl;
    cout << "ProductID     Name               Price        Quantity" << endl;
    cout << "-----------------------------------------------------------" << endl;
    for (const auto& p : products) {
        p->display();
    }
    cout << "-----------------------------------------------------------" << endl;
}