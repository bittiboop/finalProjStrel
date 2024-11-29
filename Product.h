#ifndef PRODUCT_H
#define PRODUCT_H

#include "lib.h"

class Product {
public:
    virtual int getId() const = 0;
    virtual string getName() const = 0;
    virtual double getPrice() const = 0;
    virtual string getQuantity() const = 0;
    virtual void display() const = 0;
    virtual ~Product() {}
};
 

class GeneralProduct : public Product {
    int id;
    string name;
    double price;
    double num;
    int idAdmin;

    string quantity;

public:
    

    int getId() const override;
    string getName() const override;
    double getPrice() const override;
    string getQuantity() const override;

    void display() const override;
};

void displayProducts(const vector<shared_ptr<Product>>& products);

#endif