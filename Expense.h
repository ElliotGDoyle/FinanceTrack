#ifndef ENTRY_H
#define ENTRY_H
using namespace std;
#include <string>
#include <iostream>
#include <vector>


#include "Account.h"


class Expense : public Account
{
    public:
        ENTRY();
        virtual ~ENTRY();
        
        double Getamount() { return price; }
        void Setamount(double val) { price = val; }
        void CreateEntry();
        void PrintEntry();
        //void ListExpenses(const vector<Expense>& expenses);

    protected:

    private:
        double price;
        int category;
        string date;
};

#endif // EXPENSE_H

