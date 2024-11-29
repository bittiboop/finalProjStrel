#ifndef USER_H
#define USER_H

#include "Product.h"
#include "lib.h"

class RegisteredCustomer {
    string nickname;
    string password;
    double balance = 0;
    string attempt;

public:
    string username;
    bool returns = true;

    RegisteredCustomer();

    void login(string user, string pass);
    vector<shared_ptr<Product>> viewItems(const vector<shared_ptr<Product>>& products) const;
    void addToCart(shared_ptr<Product> product);
    void makePurchase(const vector<shared_ptr<Product>>& cart);
    void applyDiscount(shared_ptr<Product> product, double discountPercentage);
    void showBalance() const;
    void addBalance();
    void displayUserData();
    void forgetPassword();
};

class Administrator {
    string adminUsername = "admin";
    string adminPassword = "admin123";

public:
    vector<RegisteredCustomer> users;
    vector<shared_ptr<Product>> products;

    bool login();
    void addUser();
    void viewUsers() const;
};



#endif