#ifndef ENTRY_H
#define ENTRY_H
using namespace std;
#include <string>
#include <iostream>
#include <vector>

class Entry {
    public:
        Entry();             //default constructor for Entry class
        virtual ~Entry();       //deconstructor for Entry class

        double Getamount() const { return amount; }         //function definition for getting amount of this entry
        void Setamount(double val) { amount = val; }        //function definition for setting amount of this entry
        string Getcategory() const { return category; }     //function definition for getting category of this entry
        void Setcategory(string val) { category = val; }    //function definition for setting category of this entry
        void AddEntryDetails();                             //function that adds details to entry object created in main
        void PrintEntry();                                  //function to print details of this Entry object
        

    protected:

    private:
        double amount;           //amount or cost of this entry
        string category;         //category of this entry, either Income or Expense
};

#endif // ENTRY_H
