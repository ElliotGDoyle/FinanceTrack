#include "Account.h"

Account::Account()
{
    //ctor
}

Account::~Account()
{
    //dtor
}

void Account::AddEntry(Entry entry)
{
    entries.push_back(entry);
}

int Account::GetEntryCount() const
{
    return static_cast<int>(entries.size());
}

Entry& Account::GetEntry(size_t idx)
{
    return entries[idx];
}

const Entry& Account::GetEntry(size_t idx) const
{
    return entries[idx];
}

float Account::CalculateBalance()
{
    float totalBalance = 0.0f;
    for (int i = 0; i < entries.size(); i++)
    {
        totalBalance += entries[i].Getamount();
    }
    return totalBalance;
}