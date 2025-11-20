#include <iostream>
#include "User.h"
#include "Expense.h"
#include "Account.h"

using namespace std;

int main()
{
    Expense e;
    e.AddExpense();

    e.PrintExpense();
    return 0;
}
