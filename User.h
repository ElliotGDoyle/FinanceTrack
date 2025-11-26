#ifndef USER_H
#define USER_H
using namespace std;
#include <string>
#include <iostream>         //includes necessary libraries


class User              
{
    public:
        User();                 //default constructor
        virtual ~User();            //deconstructor

        string Getusername() const { return username; }         //function definition for getting username
        void Setusername(string val) { username = val; }        //function definition for setting username
        string Getpassword() const { return password; }         //function definition for getting password
        void Setpassword(string val) { password = val; }        //function definition for setting password  
        
        static User CreateAccount();                            //function to create a new user account
                                                                // is static because it does not operate on an existing User object, but creates a new one
        void EditAccount(const string& username, const string& password);       //function to update this object's credentials, that takes input parameters username and password
        
        void EditAccountInteractive();                                //function to prompt and update this object's credentials interactively
        
        bool Login(const string& username, const string& password);        //login function that checks username and password of this user object, is bool so returns true or false

    private:
        string username;        //username of this user
        string password;        //password of this user 
};

#endif // USER_H
