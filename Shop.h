#ifndef SHOP_H
#define SHOP_H

#include "lib.h"
#include "product.h"

class Shop {
    vector<string> cartedItems;
    vector<int> cartedQuantity;
    vector<double> cartedPrice;

public:
    void addCart(string item, int quantity, double price);
    void displayCart() const;
};

void handleProductChoice(Shop& shop, vector<shared_ptr<Product>>& products);


#endif