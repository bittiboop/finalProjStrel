#include "Product.h"
#include "lib.h"

GeneralProduct::GeneralProduct(int id, string name, double price, string quantity)
    : id(id), name(name), price(price), quantity(quantity) {}

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
	for (const auto& product : products) {
		product->display();
	}
    cout << "-----------------------------------------------------------" << endl;
}