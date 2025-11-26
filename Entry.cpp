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
    cout<< "What type of expense is this?"<< endl;
    cin >> category;
    cout<< "What was the price of this expense?"<< endl;
    cin >> amount;


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
