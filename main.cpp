#include <iostream>
#include <vector>
#include "User.h"

#include "Expense.h"
#include "Account.h"

using namespace std;

int main()
{
    vector<User> users;
    int choice = 0;

    cout << "=== Welcome to Finance Tracker ===" << endl;

    while (true)
    {
        cout << "\n1. Create a new account" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            User newUser = User::CreateAccount();
            users.push_back(newUser);
            cout << "Account stored in system." << endl;
        }
        else if (choice == 2)
        {
            string loginUsername, loginPassword;
            cout << "\nEnter Username: ";
            cin >> loginUsername;
            cout << "Enter Password: ";
            cin >> loginPassword;

            bool loginSuccess = false;
            for (int i = 0; i < users.size(); i++)
            {
                if (users[i].Login(loginUsername, loginPassword))
                {
                    loginSuccess = true;
                    break;
                }
            }

            if (!loginSuccess && users.size() > 0)
            {
                cout << "Account not found or credentials incorrect." << endl;
            }
            else if (users.size() == 0)
            {
                cout << "No accounts exist. Please create an account first." << endl;
            }
        }
        else if (choice == 3)
        {
            cout << "Thank you for using Finance Tracker. Goodbye!" << endl;
            break;
        }
        else
        {
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
