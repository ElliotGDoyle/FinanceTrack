#include <iostream>
#include <vector>
#include "User.h"
#include "Account.h"
#include "Entry.h"

using namespace std;

void DisplayAccountMenu(User& loggedInUser, vector<Account>& userAccounts)                  //function to display account menu for logged in user
{
    int choice = 0;                                                                         //create int variable choice to hold user menu selection

    while (true)                                                                            //infinite loop to keep showing the menu until user logs out
    {
        cout << "\n=== Account Menu - " << loggedInUser.Getusername() << " ===" << endl;
        cout << "1. Create new account" << endl;
        cout << "2. Select an account" << endl;
        cout << "3. Logout" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)                                                                     //if user chooses to create new account
        {
            Account newAccount;                                                              //create a new Account object                  
            newAccount.Setuser(loggedInUser);                                                //set the user of this account to the logged in user
            newAccount.Setbalance(0);                                                        //initialize balance to zero                     
            cout << "Enter account name: ";
            string name;
            cin >> name;
            newAccount.SetaccountName(name);                                                 //set the account name to user input

            userAccounts.push_back(newAccount);                                              //add this new account to the user's list of accounts which is a vector called userAccounts        
            cout << "\nNew account '" << name << "' created successfully!" << endl;
        }
        else if (choice == 2)                                                               //if user chooses to select an existing account     
        {
            if (userAccounts.empty())                                                       //check if user has no accounts     
            {
                cout << "\nYou have no accounts. Create one first." << endl;
                continue;                                                                   //go back to the main account menu
            }

            cout << "\n--- Your Accounts ---" << endl;                                     // otherwise list account objects
            for (int i = 0; i < (int)userAccounts.size(); i++)                             //for loop that will list all accounts with index, will increment until it reaches size of userAccounts vector
            {
                cout << (i + 1) << ". " << userAccounts[i].GetaccountName();               //prints account name
                cout << " - Balance: $" << userAccounts[i].CalculateBalance() << endl;      //prints calculated balance of this account by summing all Entry amounts
            }
 
            cout << "Select an account (1-" << userAccounts.size() << "): ";
            int accountChoice;
            cin >> accountChoice;

            if (accountChoice <= 0 || accountChoice > (int)userAccounts.size())         //checks that user input is not negative and within range of available accounts
            {
                cout << "Invalid account selection." << endl;
                continue;
            }

            Account& acc = userAccounts[accountChoice - 1];                             //This create a reference(&) to the selected Account object in the userAccounts vector. this reference is called acc.
                                                                                        // It is referenced because want to able to edit the actual account object here in this menu
                                                                                        // Account detail menu: add/edit/view entries
            while (true)
            {
                cout << "\n=== " << acc.GetaccountName() << " - Balance: $" << acc.CalculateBalance() << " ===" << endl;
                cout << "1. Add entry" << endl;
                cout << "2. Edit entry" << endl;
                cout << "3. View entries" << endl;
                cout << "4. Generate report" << endl;
                cout << "5. Back" << endl;
                cout << "Enter choice: ";
                int achoice;            //temporary variable to hold account detail menu choice
                cin >> achoice;

                if (achoice == 1)
                {
                    Entry e;                //create a new Entry object called e
                    e.AddEntryDetails();        //call function to add details to this Entry object interactively
                    acc.AddEntry(e);            //add this Entry object to the selected Account's entries vector, by calling AddEntry function on a reference to the selected Account object
                    cout << "\nEntry added." << endl;
                }
                else if (achoice == 2)      //edit entry
                {
                    int ecnt = acc.GetEntryCount(); //create int variable ecnt(entry-count) to hold number of entries in this account by calling GetEntryCount function
                    if (ecnt == 0)
                    {
                        cout << "\nNo entries to edit." << endl;
                        continue;
                    }
                    cout << "\nSelect entry to edit (1-" << ecnt << "): ";
                    int eidx;           //temporary variable to hold entry index selected by user
                    cin >> eidx;
                    if (eidx <= 0 || eidx > ecnt)     // checks that user input is not negative and within range of available entries
                    {
                        cout << "\nInvalid entry selection." << endl;
                        continue;
                    }
                                                                   
                    acc.GetEntry(eidx - 1).AddEntryDetails();    //overwrite selected entry interactively by calling AddEntryDetails on the selected Entry object
                    cout << "\nEntry updated." << endl;
                }
                else if (achoice == 3)                  //view entries
                {
                    int ecnt = acc.GetEntryCount();     //create int variable ecnt(entry-count) to hold number of entries in this account by calling GetEntryCount function
                    if (ecnt == 0)                      //check if there are no entries in this account
                    {
                        cout << "\nNo entries." << endl;
                        continue;
                    }

                    cout << "\n--- Entries for " << acc.GetaccountName() << " ---" << endl;  //otherwise list all entries
                    for (int j = 0; j < ecnt; j++)                                           // for loop that will list all entries with index, will increment until it reaches size of entries vector
                    {
                        cout << (j + 1) << ". ";                //prints entry index
                        acc.GetEntry(j).PrintEntry();           //calls PrintEntry function on each Entry object to print its details
                    }
                }
                else if (achoice == 4)                  //generate report
                {
                    acc.GenerateReport();               //calls GenerateReport function to display comprehensive account report
                }
                else if (achoice == 5)                  //back to account menu
                {
                    break;                             //breaks out of the account detail menu loop and returns to the main account menu
                }
                else                                  // default case for invalid choice
                {
                    cout << "\n Invalid choice." << endl;
                }
            }
        }
        else if (choice == 3)                           //if user chooses to logout
        {
            cout << "\nLogging out..." << endl; 
            break;
        }
        else
        {
            cout << "\n Invalid choice. Try again." << endl;        //default case for invalid menu choice
        }
    }
}

int main()
{
    vector<User> users;            //creates vector to hold all User objects created in the system
    int choice = 0;                 //creates int variable choice to hold main menu selection

    cout << "\n=== Welcome to Finance Tracker ===" << endl;

    while (true)                //infinite loop to keep showing the main menu until user exits
    {
        cout << "\n1. Create a new account" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            User newUser = User::CreateAccount();    //calls static CreateAccount function to create a new User object interactively
            users.push_back(newUser);                //adds this new User object to the users vector
            cout << "\nAccount stored in system." << endl;
        }
        else if (choice == 2)
        {
            string loginUsername, loginPassword;    //creates string variables to hold login credentials
            cout << "\nEnter Username: ";
            cin >> loginUsername;
            cout << "Enter Password: ";
            cin >> loginPassword;

            bool loginSuccess = false;          //boolean variable to track if login was successful
            for (int i = 0; i < (int)users.size(); i++)     //loops through all User objects in the users vector to find a match
            {
                if (users[i].Login(loginUsername, loginPassword))       //calls Login function on each User object to check credentials
                {
                    loginSuccess = true;                    //if login is successful, set loginSuccess to true
                    vector<Account> userAccounts;           //creates a vector to hold Account objects for this logged in user
                    DisplayAccountMenu(users[i], userAccounts);     //calls function to display account menu for this logged in user, passing the User object and their accounts vector
                    break;
                }
            }

            if (!loginSuccess && users.size() > 0)      //if login was not successful and there are users in the system
            {
                cout << "\nAccount not found or credentials incorrect." << endl;
            }
            else if (users.size() == 0)            //if there are no users in the system
            {
                cout << "\nNo accounts exist. Please create an account first." << endl;
            }
        }
        else if (choice == 3)                           //if user chooses to exit
        {
            cout << "\nThank you for using Finance Tracker. Goodbye!" << endl;
            break;
        }
        else                           //default case for invalid menu choice
        {
            cout << "\n Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
