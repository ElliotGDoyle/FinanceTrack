#ifndef USER_H
#define USER_H
using namespace std;
#include <string>
#include <iostream>


class User
{
    public:
        User();
        virtual ~User();

        string Getusername() const { return username; }
        void Setusername(string val) { username = val; }
        string Getpassword() const { return password; }
        void Setpassword(string val) { password = val; }
        // Interactive factory: prompts the user and returns a new User
        static User CreateAccount();
        // Programmatic setter: set credentials on this object
        void EditAccount(const string& username, const string& password);
        // Interactive edit: prompt and update this existing User
        void EditAccountInteractive();
        // Login: verify username and password
        bool Login(const string& username, const string& password);
    protected:

    private:
        string username;
        string password;
};

#endif // USER_H
