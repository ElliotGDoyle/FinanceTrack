#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <vector>
#include "Entry.h"  
#include "User.h"
using namespace std;
#include <string>



class Account : public User
{
    public:
        Account();
        void AddEntry(Entry entry);
        int GetEntryCount() const;
        Entry& GetEntry(size_t idx);
        const Entry& GetEntry(size_t idx) const;
          
        virtual ~Account();
        void SetaccountName(string val) { accountName = val; }
        string GetaccountName() const { return accountName; }

        User Getuser() { return user; }
        void Setuser(User val) { user = val; }
        float Getbalance() const { return balance; }
        void Setbalance(float val) { balance = val; }
        float CalculateBalance();  // sums all entries

    protected:

    private:
        string accountName;
        User user;
        float balance;
        vector<Entry> entries;
};

#endif // ACCOUNT_H
