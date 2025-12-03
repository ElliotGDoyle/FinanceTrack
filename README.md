 FinanceTrack

A simple personal finance tracker to help you manage your money.

## What Does It Do?

FinanceTrack helps you keep track of your income and expenses. You can create multiple accounts (like Savings or Checking) and record all your transactions in each one. The app automatically calculates your balance and shows you where your money is going.

## Features

- **Create an Account** - Sign up with a username and password
- **Multiple Accounts** - Set up different accounts for different purposes (Savings, Bills, etc.)
- **Track Transactions** - Add income and expenses to your accounts
- **Edit Entries** - Made a mistake? You can edit any transaction
- **View All Entries** - See a list of everything you've recorded
- **Generate Reports** - Get a summary showing total income, total expenses, and your balance
- **Automatic Balance** - Your account balance updates automatically as you add entries

## How to Use

1. **First Time**: Create a new account with a username and password
2. **Login**: Enter your credentials to access your accounts
3. **Create an Account**: Set up a new account (like "Savings" or "Groceries")
4. **Add Entries**: Record your income and expenses
   - Choose if it's Income or Expense
   - Enter the amount
5. **View Reports**: See a complete summary of all your transactions

## Menu Options

### Main Menu
- Create a new account
- Login
- Exit

### Account Menu (after login)
- Create new account
- Select an account
- Logout

### Inside an Account
- Add entry
- Edit entry
- View entries
- Generate report
- Back

## Technical Info

- **Language**: C++
- **Storage**: All data is stored in memory (resets when you close the app)
- **Interface**: Command-line/console based

## How to Compile

If you have a C++ compiler installed:

```bash
g++ main.cpp User.cpp Account.cpp Entry.cpp -o FinanceTrack
```

Then run:
```bash
./FinanceTrack
```

## Note
# FinanceTrack
