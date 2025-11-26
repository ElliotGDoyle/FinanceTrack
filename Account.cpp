#include "Account.h"                        // Include the corresponding header file with function declarations

Account::Account()
{
                                            //default constructor to create an account object, is called in main when user creates a balance new account EG. Savings, Current
}

Account::~Account()
{
                                            //deconstructor for account objects(account deleter)
}

void Account::AddEntry(Entry entry)         //function to add an Entry object named entry to the vector of entries
{
    entries.push_back(entry);               //Pushes or adds this particular entry object to the entries vector, which is a list of all Entry objects associated with this Account
}

int Account::GetEntryCount()           //function to get the number of Entry objects in the entries vector which returns an integer size
{
    return (int)(entries.size());           //returns an integer which is the size(total amount) property of the entries vector of this particular Account object
}

Entry& Account::GetEntry(int idx)           //function that takes an int input called idx(index) and returns a reference to an Entry object, using index to find the correct Entry in the vector
{                                           //It returns a reference to an object, not another object which is a copy of this entry. So you change the acutal Entry
                                            //If there was no & before entry, it would return a copy of the Entry object at that index, and any changes made would not affect the original Entry in the vector. 
    return entries[idx];                    //returns the particular Entry object located at whatever index in the entries vector           
}


float Account::CalculateBalance()          //function to calculate the total balance of this Account by summing all Entry amounts
{
    float totalBalance = 0.0f;             //initializes a float variable totalBalance to zero, which will hold the cumulative balance
    for (int i = 0; i < entries.size(); i++)        // loops through each Entry object in the entries vector
    {
        totalBalance += entries[i].Getamount();     //adds amount of each Entry object to the totalBalance
    }
    return totalBalance;                     //returns the final calculated total balance
}