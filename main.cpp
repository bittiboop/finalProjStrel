#include "domain.h"
#include "lib.h"

map<int, double> discounts;
double totalPrice = 0;
int totalproducts = 0;

int main()
{
    vector<shared_ptr<Product>> products = {
        make_shared<GeneralProduct>(1, "Laptop", 5000.0, "10"),
        make_shared<GeneralProduct>(2, "Phone", 3000.0, "20"),
        make_shared<GeneralProduct>(3, "T-Shirt", 50.0, "100"),
        make_shared<GeneralProduct>(4, "Boxers", 30.0, "150"),
        make_shared<GeneralProduct>(5, "Powerbank", 200.0, "50")
    };

    Administrator admin;

    while (true) {
        int option = 0;
        cout << "\n\t\t************************************************\n";
        cout << "\t\t*                                              *\n";
        cout << "\t\t*   Welcome to Online Shopping Site            *\n";
        cout << "\t\t*                                              *\n";
        cout << "\n\t\tAre you a Customer or an Admin?\n";
        cout << "\t\t-------------------------------------------\n";
        cout << "\t\t1. Customer" << endl;
        cout << "\t\t2. Admin" << endl;
        cout << "\t\t-------------------------------------------\n";
        cout << "\t\tEnter an option: ";
        cin >> option;
        cin.ignore();

        if (option == 1) {
            RegisteredCustomer user;
            Shop shop;

            while (true) {
                cout << "\n\t\t\t     Welcome to Online Shopping Site" << endl;
                cout << "\t\t\t  What would you like to buy?" << endl << endl;
                cout << "1. View Products" << endl;
                cout << "2. My Account and Balance" << endl;
                cout << "3. Show my carted Products and Checkout" << endl;
                cout << "4. Return To the Main" << endl;
                cout << "Enter an option: ";
                cin >> option;
                cin.ignore();

                if (option == 4) {
                    break; 
                }
                switch (option){
                    case 1:
                        displayProducts(products);
                        handleProductChoice(shop, products);
                        break;
                    case 2:
                        int userChoice;
                        cout << endl << "1. Check Balance " << endl;
                        cout << "2. Add More Balance " << endl;
                        cout << "3. Show my all data " << endl;
                        cout << "4. Reset password " << endl;
                        cout << "5. Return to Main Menu " << endl;
                        cin >> userChoice;
                        cin.ignore();
                        if (userChoice == 1)
                            user.showBalance();
                        else if (userChoice == 2)
                            user.addBalance();
                        else if (userChoice == 3)
                            user.displayUserData();
                        else if (userChoice == 4)
                            user.forgetPassword();
                        break;
                    case 3:
                        shop.displayCart();
                        user.checkout();
                        if (!user.returns) continue;
                        else exit(0);
                    default:
                        cout << "Invalid Option!!!" << endl;
                    
                }
            }
        }
        else if (option == 2) {
            if (!admin.login()) continue;
            while (true) {
                cout << "\n\t\t\tAdmin Panel" << endl;
                cout << "1. Add User" << endl;
                cout << "2. View Users" << endl;
                cout << "3. Delete Product" << endl;
                cout << "4. Add Item" << endl;
                cout << "5. Set Discount" << endl;
                cout << "6. Return to Main Menu" << endl;
                cout << "Enter an option: ";
				cin >> option;
				cin.ignore();


                if (option == 6)
                {
                    break;
                }

                switch (option)
                {
				case 1:
					admin.addUser();
					break;
				case 2:
					admin.viewUsers();
					break;
				case 3:
                    admin.deleteProduct();
                    products = admin.products;
                    break;
				case 4:
                    admin.addItem();
                    products = admin.products;
                    break;
				case 5:
                    int productId;
                    double discountPercentage;
                    cout << "Enter Product ID to set discount: ";
                    cin >> productId;
                    cout << "Enter discount percentage (e.g., 10 for 10%): ";
                    cin >> discountPercentage;
                    admin.setDiscountForProducts(productId, discountPercentage);
                    break;
				default:
					cout << "Invalid Choice!!!" << endl;
                }
            }
        }
        else 
            {
            cout << "Invalid Option!!!" << endl;
        }
    }

	return 0;
}