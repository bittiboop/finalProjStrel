#include "Shop.h"
#include "User.h"
#include "lib.h"

void Shop::addCart(string item, int quantity, double price) {
    cartedItems.push_back(item);
    cartedQuantity.push_back(quantity);
    cartedPrice.push_back(price);
    cout << item << " Added to the cart" << endl;
}

void Shop::displayCart() const {
    cout << "\n\nItems in the cart:\n" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Quantity      Name                               Price" << endl;
    cout << "-----------------------------------------------------------" << endl;
    for (size_t i = 0; i < cartedItems.size(); ++i) {
        cout << "  " << cartedQuantity[i];
        cout << "\t     " << cartedItems[i];
        cout << "\t     \t\t" << cartedPrice[i] << " Hrivnas " << endl;
    }
    cout << endl << "-----------------------------------------------------------" << endl;
    cout << "\tTotal price is: \t\t\t" << totalPrice << " Hrivnas " << endl;
}

void handleProductChoice(Shop& shop, vector<shared_ptr<Product>>& products) {
    int choice, quantity;
    cout << "Enter a Product ID: ";
    cin >> choice;
    cout << "Enter quantity: ";
    cin >> quantity;

    for (auto& p : products) {
        if (p->getId() == choice) {
            double finalPrice = p->getPrice();
            if (discounts.find(choice) != discounts.end()) {
                cout << "You have a " << discounts[choice] << "% discount for Product " << p->getName() << "." << endl;
                cout << "Do you want to apply the discount? (1 for yes, 2 for no): ";
                int applyDiscount;
                cin >> applyDiscount;
                if (applyDiscount == 1) {
                    double discountedPrice = finalPrice - (finalPrice * discounts[choice] / 100);
                    cout << "Original Price: " << finalPrice << " Hrivnas " << endl;
                    cout << "Discounted Price: " << discountedPrice << " Hrivnas " << endl;
                    finalPrice = discountedPrice;
                }
            }
            shop.addCart(p->getName(), quantity, finalPrice * quantity);
            totalPrice += finalPrice * quantity;
            cout << "\nCurrent total is " << totalPrice << " Hrivnas " << endl;
            cout << "***************************" << endl;
            totalproducts++;
            break;
        }
    }
}