#include "User.h"
#include "Product.h"
#include "lib.h"

RegisteredCustomer::RegisteredCustomer() {
    cout << "\n\t\t\tWelcome to Online Shopping System" << endl;
    cout << "\t\tPlease create an Account to continue Shopping" << endl;
    cout << "Enter Your username: ";
    getline(cin, username);
    cout << "Enter Your Password: ";
    getline(cin, password);
    cout << "Enter a nickname(This will be used to reset password): ";
    getline(cin, nickname);
    cout << "Add some balance to buy products:  ";
    cin >> balance;
    cin.ignore();
}

void RegisteredCustomer::login(string user, string pass) {
    if (username == user && password == pass) {
        cout << "Login successful!" << endl;
    }
    else {
        cout << "Login failed!" << endl;
    }
}

vector<shared_ptr<Product>> RegisteredCustomer::viewItems(const vector<shared_ptr<Product>>& products) const 
{
    return products;
}

void RegisteredCustomer::addToCart(shared_ptr<Product> product) {
    // adding product to cart
}

void RegisteredCustomer::makePurchase(const vector<shared_ptr<Product>>& cart) {
    // making a purchase
}

void RegisteredCustomer::applyDiscount(shared_ptr<Product> product, double discountPercentage) {
    // applying discount
}


void RegisteredCustomer::showBalance() const {
    cout << "\n\t\t\t  Your balance is " << balance << " Hrivnas" << endl;
    cout << "\t\t-----------------------------------------" << endl;
}

void RegisteredCustomer::addBalance() {
    int extraBalance;
    cout << "Enter amount to add: ";
    cin >> extraBalance;
    balance += extraBalance;
    cout << "\t\t\t " << extraBalance << " Hrivnas added successfully " << endl;
    cout << "\t\t\tCurrent Balance is " << balance << " Hrivnas" << endl;
    cout << "\t\t-----------------------------------------" << endl;
}

void RegisteredCustomer::displayUserData() {
attemptagain:
    cout << "Enter Your password: ";
    getline(cin, attempt);
    if (attempt == password) {
        cout << "\n\t\t\tYour UserName is " << username << endl;
        cout << "\t\t\tYour nickname is " << nickname << endl;
        cout << "\t\t\tYour Balance is " << balance << " Hrivnas" << endl;
        cout << "\t\t-----------------------------------------" << endl;
    }
    else {
        cout << "Wrong password :( Try Again!" << endl;
        goto attemptagain;
    }
}

void RegisteredCustomer::forgetPassword() {
    string forgetNick;
forgetNickname:
    cout << "Enter your nickname: ";
    getline(cin, forgetNick);
    if (forgetNick == nickname) {
        cout << "Enter your new Password: ";
        getline(cin, password);
        cout << "Password reset Successful....." << endl;
    }
    else {
        cout << "Wrong Nickname :( Try Again!" << endl;
        goto forgetNickname;
    }
}


//ADMINISTRATOR realisation
bool Administrator::login() {
    string username, password;
    cout << "Enter Admin Username: ";
    getline(cin, username);
    cout << "Enter Admin Password: ";
    getline(cin, password);
    if (username == adminUsername && password == adminPassword) {
        cout << "Login successful!" << endl;
        return true;
    }
    else {
        cout << "Login failed!" << endl;
        return false;
    }
}

void Administrator::addUser() {
    RegisteredCustomer newUser;
    users.push_back(newUser);
    cout << "User added successfully!" << endl;
}

void Administrator::viewUsers() const {
    cout << "\n\nList of Users:\n" << endl;
    for (const auto& u : users) {
        cout << "Username: " << u.username << endl;
    }
}
