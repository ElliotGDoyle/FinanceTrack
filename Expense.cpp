#include "Expense.h"
using namespace std;
#include <string>
#include <iostream>
#include <vector>

Expense::Expense()
{
    //ctor
}

Expense::~Expense()
{
    //dtor
}

void Expense::AddExpense()
{
    cout<< "What type of expense is this?"<< endl;
    cin >> category;
    cout<< "What was the price of this expense?"<< endl;
    cin >> amount;


}


void Expense::PrintExpense(){

cout<< "Cost is "<< amount << " $."<< endl;
cout<< "Category is "<< category << " ."<< endl;


}


/*void Expense::ListExpenses(const vector<Expense>& expenses)
{
    if (expenses.empty()) {
        cout << "No expenses recorded.\n";
        return;
    }

    cout << "\n---- All Expenses ----\n";
    for ( Expense& e : expenses)
    {
        cout << "Category: " << e.GetCategory()
             << " | Amount: $" << e.GetAmount() << endl;
    }
}
*/
