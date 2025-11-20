#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>

#include "User.h"
using namespace std;
#include <string>



class Account : public User
{
    public:
        Account();
        virtual ~Account();

        User Getuser() { return user; }
        void Setuser(User val) { user = val; }
        float Getbalance() { return balance; }
        void Setbalance(float val) { balance = val; }

    protected:

    private:
        User user;
        float balance;
};

#endif // ACCOUNT_H
