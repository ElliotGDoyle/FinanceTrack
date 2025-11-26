#ifndef ENTRY_H
#define ENTRY_H
using namespace std;
#include <string>
#include <iostream>
#include <vector>

class Entry {
    public:
        Entry();
        virtual ~Entry();

        double Getamount() const { return amount; }
        void Setamount(double val) { amount = val; }
        string Getcategory() const { return category; }
        void Setcategory(string val) { category = val; }
        void AddEntry();
        void PrintEntry();
        //void ListEntries( vector<Entry>& expenses);

    protected:

    private:
        double amount;
        string category;
};

#endif // ENTRY_H
