#include <iostream>
#include "User.h"
#include "Expense.h"
#include "Account.h"

using namespace std;

int main()
{
    Expense expense1;
    expense1.AddExpense();

    expense1.PrintExpense();
    return 0;
}
