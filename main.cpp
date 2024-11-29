#include "domain.h"
#include "lib.h"

int main()
{
    vector<shared_ptr<Product>> products = {
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
                
            }
        }
        else if (option == 2) {
            if (!admin.login()) continue;
            while (true) {
                cout << "\n\t\t\tAdmin Panel" << endl;
                
            }
        }
        else {
            cout << "Invalid Option!!!" << endl;
        }
    }

	return 0;
}