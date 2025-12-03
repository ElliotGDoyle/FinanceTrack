#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits>
#include "User.h"
#include "Account.h"
#include "Entry.h"

using namespace std;

// Simple CSV persistence
const string USERS_FILE = "users.csv";
const string ACCOUNTS_FILE = "accounts.csv"; // username,accountName
const string ENTRIES_FILE = "entries.csv";   // username,accountName,category,amount

// Users
void SaveUsers(const vector<User>& users)
{
    ofstream out(USERS_FILE, ios::trunc);
    for (const auto& u : users)
    {
        out << u.Getusername() << "," << u.Getpassword() << "\n";
    }
}

void LoadUsers(vector<User>& users)
{
    ifstream in(USERS_FILE);
    if (!in.is_open()) return;
    string line;
    while (getline(in, line))
    {
        if (line.empty()) continue;
        size_t c1 = line.find(',');
        if (c1 == string::npos) continue;
        string uname = line.substr(0, c1);
        string pwd = line.substr(c1 + 1);
        User u; u.Setusername(uname); u.Setpassword(pwd);
        users.push_back(u);
    }
}

// Accounts for one user: rewrite that user's rows
void SaveAccountsForUser(const string& username, const vector<Account>& userAccounts)
{
    // Read existing (keep other users' rows)
    vector<string> otherRows;
    {
        ifstream in(ACCOUNTS_FILE);
        string line;
        while (getline(in, line))
        {
            if (line.rfind(username + ",", 0) == 0) continue; // skip this user's rows
            if (!line.empty()) otherRows.push_back(line);
        }
    }
    ofstream out(ACCOUNTS_FILE, ios::trunc);
    for (const auto& r : otherRows) out << r << "\n";
    for (const auto& acc : userAccounts)
    {
        out << username << "," << acc.GetaccountName() << "\n";
    }
}

void LoadAccountsForUser(const string& username, vector<Account>& userAccounts)
{
    ifstream in(ACCOUNTS_FILE);
    if (!in.is_open()) return;
    string line;
    while (getline(in, line))
    {
        if (line.empty()) continue;
        size_t c1 = line.find(',');
        if (c1 == string::npos) continue;
        string u = line.substr(0, c1);
        if (u != username) continue;
        string accName = line.substr(c1 + 1);
        Account acc;
        acc.SetaccountName(accName);
        acc.Setbalance(0);
        userAccounts.push_back(acc);
    }
}

// Entries for one user: rewrite that user's rows
void SaveEntriesForUser(const string& username, const vector<Account>& userAccounts)
{
    vector<string> otherRows;
    {
        ifstream in(ENTRIES_FILE);
        string line;
        while (getline(in, line))
        {
            if (line.rfind(username + ",", 0) == 0) continue;
            if (!line.empty()) otherRows.push_back(line);
        }
    }
    ofstream out(ENTRIES_FILE, ios::trunc);
    for (const auto& r : otherRows) out << r << "\n";
    for (const auto& acc : userAccounts)
    {
        for (int i = 0; i < acc.GetEntryCount(); i++)
        {
            const Entry& e = acc.GetEntry((size_t)i);
            out << username << "," << acc.GetaccountName() << ","
                << e.Getcategory() << "," << fixed << setprecision(2) << e.Getamount() << "\n";
        }
    }
}

void LoadEntriesForUser(const string& username, vector<Account>& userAccounts)
{
    ifstream in(ENTRIES_FILE);
    if (!in.is_open()) return;
    string line;
    while (getline(in, line))
    {
        if (line.empty()) continue;
        // username,accountName,category,amount
        size_t c1 = line.find(',');
        if (c1 == string::npos) continue;
        string u = line.substr(0, c1);
        if (u != username) continue;
        size_t c2 = line.find(',', c1 + 1);
        size_t c3 = line.find(',', c2 + 1);
        if (c2 == string::npos || c3 == string::npos) continue;
        string accName = line.substr(c1 + 1, c2 - c1 - 1);
        string category = line.substr(c2 + 1, c3 - c2 - 1);
        double amount = 0.0;
        try { amount = stod(line.substr(c3 + 1)); } catch (...) { amount = 0.0; }
        // find account
        for (auto& acc : userAccounts)
        {
            if (acc.GetaccountName() == accName)
            {
                Entry e; e.Setcategory(category); e.Setamount(amount);
                acc.AddEntry(e);
                break;
            }
        }
    }
}

void DisplayAccountMenu(User& loggedInUser, vector<Account>& userAccounts)
{
    int choice = 0;

    while (true)
    {
        cout << "\n" << string(50, '=') << endl;
        cout << "  Account Menu - " << loggedInUser.Getusername() << endl;
        cout << string(50, '=') << endl;
        cout << "1. Create new account" << endl;
        cout << "2. Select an account" << endl;
        cout << "3. Logout" << endl;
        cout << string(50, '=') << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            Account newAccount;
            newAccount.Setuser(loggedInUser);
            newAccount.Setbalance(0);
            cout << "Enter account name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string name;
            cin >> name;
            newAccount.SetaccountName(name);

            userAccounts.push_back(newAccount);
            SaveAccountsForUser(loggedInUser.Getusername(), userAccounts);
            cout << "\nNew account '" << name << "' created successfully!" << endl;
        }
        else if (choice == 2)
        {
            if (userAccounts.empty())
            {
                cout << "\n You have no accounts. Create one first." << endl;
                continue;
            }

            cout << "\n" << string(50, '-') << endl;
            cout << "  Your Accounts" << endl;
            cout << string(50, '-') << endl;
            for (int i = 0; i < (int)userAccounts.size(); i++)
            {
                cout << setw(2) << (i + 1) << ". " << left << setw(24) << userAccounts[i].GetaccountName()
                     << right << " | Balance: $" << fixed << setprecision(2) << userAccounts[i].CalculateBalance() << endl;
            }
            cout << string(50, '-') << endl;

            cout << "Select an account (1-" << userAccounts.size() << "): ";
            int accountChoice;
            cin >> accountChoice;

            if (accountChoice <= 0 || accountChoice > (int)userAccounts.size())
            {
                cout << "Invalid account selection." << endl;
                continue;
            }

            Account& acc = userAccounts[accountChoice - 1];

            // Account detail menu: add/edit/view entries
            while (true)
            {
                cout << "\n" << string(50, '=') << endl;
                cout << "  " << acc.GetaccountName() << " - Balance: $" << fixed << setprecision(2) << acc.CalculateBalance() << endl;
                cout << string(50, '=') << endl;
                cout << "1. Add entry" << endl;
                cout << "2. Edit entry" << endl;
                cout << "3. View entries" << endl;
                cout << "4. Back" << endl;
                cout << string(50, '=') << endl;
                cout << "Enter choice: ";
                int achoice;
                cin >> achoice;

                if (achoice == 1)
                {
                    Entry e;
                    e.AddEntry();
                    acc.AddEntry(e);
                    SaveEntriesForUser(loggedInUser.Getusername(), userAccounts);
                    cout << "\n\xE2\x9C\x93 Entry added." << endl;
                }
                else if (achoice == 2)
                {
                    int ecnt = acc.GetEntryCount();
                    if (ecnt == 0)
                    {
                        cout << "\n\xE2\x9C\x97 No entries to edit." << endl;
                        continue;
                    }
                    cout << "\nSelect entry to edit (1-" << ecnt << "): ";
                    int eidx;
                    cin >> eidx;
                    if (eidx <= 0 || eidx > ecnt)
                    {
                        cout << "\n\xE2\x9C\x97 Invalid entry selection." << endl;
                        continue;
                    }
                    // overwrite selected entry interactively
                    acc.GetEntry(eidx - 1).AddEntry();
                    SaveEntriesForUser(loggedInUser.Getusername(), userAccounts);
                    cout << "\n\xE2\x9C\x93 Entry updated." << endl;
                }
                else if (achoice == 3)
                {
                    int ecnt = acc.GetEntryCount();
                    if (ecnt == 0)
                    {
                        cout << "\n\xE2\x9C\x97 No entries." << endl;
                        continue;
                    }
                    cout << "\n" << string(50, '-') << endl;
                    cout << "  Entries for " << acc.GetaccountName() << endl;
                    cout << string(50, '-') << endl;
                    for (int j = 0; j < ecnt; j++)
                    {
                        cout << setw(2) << (j + 1) << ". ";
                        acc.GetEntry(j).PrintEntry();
                    }
                    cout << string(50, '-') << endl;
                }
                else if (achoice == 4)
                {
                    break; // back to account menu
                }
                else
                {
                    cout << "\n\xE2\x9C\x97 Invalid choice." << endl;
                }
            }
        }
        else if (choice == 3)
        {
            cout << "\nLogging out..." << endl;
            break;
        }
        else
        {
            cout << "\n\xE2\x9C\x97 Invalid choice. Try again." << endl;
        }
    }
}

int main()
{
    vector<User> users;
    LoadUsers(users);
    int choice = 0;

    cout << "\n" << string(50, '=') << endl;
    cout << "  Welcome to Finance Tracker" << endl;
    cout << string(50, '=') << endl;

    while (true)
    {
        cout << "\n1. Create a new account" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << string(50, '=') << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            User newUser = User::CreateAccount();
            users.push_back(newUser);
            SaveUsers(users);
            cout << "\n\xE2\x9C\x93 Account stored in system." << endl;
        }
        else if (choice == 2)
        {
            string loginUsername, loginPassword;
            cout << "\nEnter Username: ";
            cin >> loginUsername;
            cout << "Enter Password: ";
            cin >> loginPassword;

            bool loginSuccess = false;
            for (int i = 0; i < (int)users.size(); i++)
            {
                if (users[i].Login(loginUsername, loginPassword))
                {
                    loginSuccess = true;
                    vector<Account> userAccounts;
                    LoadAccountsForUser(loginUsername, userAccounts);
                    LoadEntriesForUser(loginUsername, userAccounts);
                    DisplayAccountMenu(users[i], userAccounts);
                    // Save any changes on logout from account menu
                    SaveAccountsForUser(loginUsername, userAccounts);
                    SaveEntriesForUser(loginUsername, userAccounts);
                    break;
                }
            }

            if (!loginSuccess && users.size() > 0)
            {
                cout << "\n\xE2\x9C\x97 Account not found or credentials incorrect." << endl;
            }
            else if (users.size() == 0)
            {
                cout << "\n\xE2\x9C\x97 No accounts exist. Please create an account first." << endl;
            }
        }
        else if (choice == 3)
        {
            cout << "\nThank you for using Finance Tracker. Goodbye!" << endl;
            break;
        }
        else
        {
            cout << "\n\xE2\x9C\x97 Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
