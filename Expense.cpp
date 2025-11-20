#include "Expense.h"
using namespace std;
#include <string>
#include <iostream>
#include <vector>



void Entry::CreateEntry()
{
    int type;
    cout<< "What type of entry is this?"<< endl<< "1. Expense "<< endl<< "2. Income "<< endl;
    cin >> type;
    if (type = 1){
        cout<< "Expense Entry:"<< endl;
        cout<< "What category does this expense belong to?"<< endl;
        cout<< "1. Food "<< endl<< "2. Rent "<< endl<< "3. Utilities "<< endl<< "4. Entertainment "<< endl<< "5. Transport "<< endl;
        cin >> category;
        return;
    }
    
    cout<< "What is amount of this entry in euro?"<< endl;
    cin >> price;
    cout<< "When was date of purchase?"<< endl;
    cin >> date;


}


void Expense::PrintEntry(){

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


