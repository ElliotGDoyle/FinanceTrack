#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <vector>
#include "Entry.h"  
#include "User.h"
using namespace std;
#include <string>



class Account                               //definition of Account class which holds a balance and list of entries, linked to a User
{
    public:                                 //public getters and setters as well as functions declarations
        Account();                          //default constructor declaration
        void AddEntry(Entry entry);         //function declaration to add an Entry object to this Account's entries vector
        int GetEntryCount() ;               //function declaration to get the number of Entry objects in the entries vector which returns an integer size       
        Entry& GetEntry(int idx);           //function declaration to get a reference to an Entry object at a specific index in the entries vector
        float CalculateBalance();           //function declaration to calculate the total balance by summing all entries
        void GenerateReport();              //function declaration to generate a report showing all entries with total income and expenses

          
        ~Account();                         //deconstructor declaration
        void SetaccountName(string val) { accountName = val; }   //full function definition for setting account name   
        string GetaccountName() const { return accountName; }    //function definition for getting account name

        User Getuser() { return user; }         //function definition for getting user associated with this account
        void Setuser(User val) { user = val; }    //function definition for setting user associated with this account
        float Getbalance() const { return balance; }    //function definition for getting balance of this account
        void Setbalance(float val) { balance = val; }  //function definition for setting balance of this account
        
    protected:

    private:
        string accountName;               //name of this account EG. Savings, Current
        User user;                        //User object associated with this account
        float balance;                   //balance of this account
        vector<Entry> entries;           //vector of Entry objects associated with this account
};

#endif // ACCOUNT_H
