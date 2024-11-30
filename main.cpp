#include "domain.h"
#include "lib.h"

int main()
{
    vector<shared_ptr<Product>> products = {
        make_shared<GeneralProduct>(1, "Laptop", 5000.0, "10"),
        make_shared<GeneralProduct>(2, "Smartphone", 3000.0, "20"),
        make_shared<GeneralProduct>(3, "T-Shirt", 50.0, "100"),
        make_shared<GeneralProduct>(4, "Boxers", 30.0, "150"),
        make_shared<GeneralProduct>(5, "Headphones", 200.0, "50")
    };

    Administrator admin;

    while (true) {
        int option = 0;
        cout << "\n\t\t************************************************\n";
        cout << "\t\t*                                              *\n";
        cout << "\t\t*   Welcome to Online Shopping Site           *\n";
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
                    case 2:
                    case 3:
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
                cout << "Enter an option: ";
				cin >> option;
				cin.ignore();
                if (option == 3)
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