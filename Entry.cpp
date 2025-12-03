#include "Entry.h"
using namespace std;
#include <string>
#include <iostream>
#include <vector>

Entry::Entry()
{
    //ctor
}

Entry::~Entry()
{
    //dtor
}


void Entry::AddEntry()
{
    cout<< "What type of entry is this?"<< endl;
    cout<< "Income or Expense?"<< endl;
    cout <<"1. Income"<< endl;
    cout <<"2. Expense"<< endl;

    int Input;
    cin >> Input;
    if (Input == 1){
        category = "Income";
    }
    else if (Input == 2){
        category = "Expense";
    }
    else{
        cout<< "Invalid input. Defaulting to Expense."<< endl;
        category = "Expense";
    }

   
   
    cout<< "What was the price of this entry?"<< endl;
    cin >> amount;
    if (category == "Expense"){
       cout<< "Expense:"<< endl;
       amount = -abs(amount); // ensure amount is negative 
    }
    else
    {
         cout<< "Income:"<< endl;
         amount = abs(amount); // ensure amount is positive
    }
    


}


void Entry::PrintEntry(){

cout<< "Cost is "<< amount << " $."<< endl;
cout<< "Category is "<< category << " ."<< endl;


}


/*void Entry::ListEntries(const vector<Entry>& expenses)
{
    if (expenses.empty()) {
        cout << "No expenses recorded.\n";
        return;
    }

    cout << "\n---- All Expenses ----\n";
    for ( Entry& e : expenses)
    {
        cout << "Category: " << e.GetCategory()
             << " | Amount: $" << e.GetAmount() << endl;
    }
}
*/
