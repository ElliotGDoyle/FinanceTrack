#ifndef EXPENSE_H
#define EXPENSE_H
using namespace std;
#include <string>
#include <iostream>
#include <vector>


#include "Account.h"


class Expense : public Account
{
    public:
        Expense();
        virtual ~Expense();

        double Getamount() { return amount; }
        void Setamount(double val) { amount = val; }
        void AddExpense();
        void PrintExpense();
        void ListExpenses(const vector<Expense>& expenses);

    protected:

    private:
        double amount;
        string category;
};

#endif // EXPENSE_H
