#include "User.h"
#include "Product.h"
#include "lib.h"

RegisteredCustomer::RegisteredCustomer() {
    cout << "\n\t\t\tWelcome to Online Shopping Site" << endl;
    cout << "\t\tPlease create an account to continue shopping" << endl;
    cout << "Enter your username: ";
    getline(cin, username);
    cout << "Enter your Password: ";
    getline(cin, password);
    cout << "Enter a nickname(This is for reseting password): ";
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

void RegisteredCustomer::checkout() {
    string checkpass;
trypassagain:
    cout << endl << "Enter your password to confirm Checkout or (Type 0 to return Main Menu): ";
    getline(cin, checkpass);
    if (checkpass == "0") {
        returns = false;
    }
    else if (checkpass == password) {
        if (balance < totalPrice) {
            cout << "\nInsufficient Balance!!" << endl;
            cout << "Please add balance from (My Account and balance)" << endl << endl;
            returns = false;
        }
        else {
            balance -= totalPrice;
            cout << "\n\n\t\t-------------------------------------------" << endl;
            cout << "\t\t\t    Purchase successful !!! " << endl;
            cout << "\t\t     Your current balance is " << balance << " Hrivnas " << endl;
            cout << "\t\t-------------------------------------------\n\n\n" << endl;
            cout << "\t\t******************************************* ";
            cout << endl << "\t\t* Thank you for shopping with Online Shopping Site *" << endl;
            cout << "\t\t*      We hope to see you again      *" << endl;
            cout << "\t\t*******************************************\n\n\n" << endl;
            returns = true;
        }
    }
    else {
        cout << endl << "Wrong Password!!! " << endl;
        cout << "If forgot password please go my acount and balance to reset password " << endl;
        goto trypassagain;
    }
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

void Administrator::addItem() {
    int id;
    string name;
    double price;
    string quantity;
    cout << "Enter Product ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Product Name: ";
    getline(cin, name);
    cout << "Enter Product Price: ";
    cin >> price;
    cin.ignore();
    cout << "Enter Product Quantity: ";
    getline(cin, quantity);

    products.push_back(make_shared<GeneralProduct>(id, name, price, quantity));
    cout << "Product added successfully!" << endl;
}
void Administrator::updateItemDetails(int productId, const string& newName, double newPrice, const string& newQuantity) {
    for (auto& product : products) {
        if (product->getId() == productId) {
            product = make_shared<GeneralProduct>(productId, newName, newPrice, newQuantity);
        }
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

void Administrator::deleteProduct() {
    int productId;
    cout << "Enter Product ID to delete: ";
    cin >> productId;
    cin.ignore();
    products.erase(
        remove_if(products.begin(), products.end(), [&](shared_ptr<Product>& p) { return p->getId() == productId; }),
        products.end()
    );
    cout << "Product deleted successfully!" << endl;
}

void Administrator::setDiscountForProducts(int productId, double discountPercentage) {
    if (discountPercentage < 0 || discountPercentage > 100) {
        cout << "Invalid discount percentage! Please enter a value between 0 and 100." << endl;
        return;
    }
    discounts[productId] = discountPercentage;
    cout << "Discount set successfully for product ID: " << productId << endl;
}

void Administrator::viewProducts() const {
    cout << "\n\nList of Products:\n" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "ID     Name               Price        Quantity" << endl;
    cout << "-----------------------------------------------------------" << endl;
	for (const auto& product : products) {
		product->display();
	}
    cout << "-----------------------------------------------------------" << endl;
}