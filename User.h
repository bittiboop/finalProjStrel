#ifndef USER_H
#define USER_H

#include "Product.h"
#include "Shop.h"
#include "lib.h"

extern double totalPrice;
extern map<int, double> discounts;
extern int totalproducts;

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
    void checkout();
    void showBalance() const;
    void addBalance();
    void displayUserData();
    void forgetPassword();
};

class Administrator {
    string adminUsername = "admin";
    string adminPassword = "admin123456";

public:
    vector<RegisteredCustomer> users;
    vector<shared_ptr<Product>> products;

    bool login();
    void addItem();
    void viewUsers() const;

    void deleteProduct();
    void addUser();
    
    void viewProducts() const;
    void updateItemDetails(int productId, const string& newName, double newPrice, const string& newQuantity);
    void setDiscountForProducts(int productId, double discountPercentage);
};
#endif