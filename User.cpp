#include "User.h"
using namespace std;
#include <string>
#include <iostream>


User::User()
{
        //default constructor
}

User::~User()
{
    //deconstructor
}


User User::CreateAccount()   //function to create a new user account, interactively
{
    User u;                  //creates a new User object u
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
    return u;       //returns the newly created User object with set username and password
}

void User::EditAccount(const string& username, const string& password) //function to update this object's credentials, that takes input parameters username and password
{
    Setusername(username);
    Setpassword(password);
}


void User::EditAccountInteractive()  //function to prompt and update this object's credentials interactively
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

    
bool User::Login(const string& username, const string& password)       //login function that checks username and password of this user object, is bool so returns true or false
{                                                                      //uses referenced parameters to avoid copying strings
    if (this->username == username && this->password == password)  //checks if the login attempt matches the details of this User object
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
    
    