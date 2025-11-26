#include "User.h"
using namespace std;
#include <string>
#include <iostream>


User::User()
{
 
}

User::~User()
{
    //dtor
}


User User::CreateAccount()
{
    User u;
    string username;
    string password;
    string confirm_password;

    cout << "Creating account..." << endl;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;
    cout << "Confirm your password: ";
    cin >> confirm_password;

    while (password != confirm_password)
    {
        cout << "Password did not match. Please try again." << endl;
        cout << "Enter Password: ";
        cin >> password;
        cout << "Confirm your password: ";
        cin >> confirm_password;
    }

    u.Setusername(username);
    u.Setpassword(password);
    cout << "Account created successfully!" << endl;
    return u;
}
// Programmatic setter: update this object's credentials
void User::EditAccount(const string& username, const string& password)
{
    Setusername(username);
    Setpassword(password);
}

// Instance interactive edit: prompt and update this object's credentials
void User::EditAccountInteractive()
{
    string username;
    string password;
    string confirm_password;

    cout << "Edit account..." << endl;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;
    cout << "Confirm your password: ";
    cin >> confirm_password;

    while (password != confirm_password)
    {
        cout << "Password did not match. Please try again." << endl;
        cout << "Enter Password: ";
        cin >> password;
        cout << "Confirm your password: ";
        cin >> confirm_password;
    }

    Setusername(username);
    Setpassword(password);
    cout << "Account updated successfully!" << endl;
}

// Login: verify credentials
bool User::Login(const string& username, const string& password)
{
    if (this->username == username && this->password == password)
    {
        cout << "Login successful! Welcome, " << username << "!" << endl;
        return true;
    }
    else
    {
        cout << "Login failed! Invalid username or password." << endl;
        return false;
    }
}
    
    