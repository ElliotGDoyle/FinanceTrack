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

        string Getusername() { return username; }
        void Setusername(string val) { username = val; }
        string Getpassword() { return password; }
        void Setpassword(string val) { password = val; }

    protected:

    private:
        string username;
        string password;
};

#endif // USER_H
