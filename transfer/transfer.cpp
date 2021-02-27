#include "transfer.h"

void Transfer::transfer(float amount, Account& account1, Account& account2)
{
    account1.addBalance(amount);
    account2.removeBalance(amount);
}

bool Transfer::startTransaction(AdminUser& user){
    string name;
    string nameString;
    string bankAccountID;
    string bankAccountID2;
    string bankAccountIDString;
    string bankAccountIDString2;
    string amount;
    string amountString;

    // User Inputs
    cout << "Enter Account Holder’s Name:";
    cin >> name;
    
    cout << "Enter account number to transfer from:";
    cin >> bankAccountID;

    cout << "Enter account number to transfer to:";
    cin >> bankAccountID2;

    cout << "Enter amount to transfer:";
    cin >> amount;

    // Validate User Input
    if (!isValidAccountNumber(bankAccountID)){
        cout << "Error: invalid account number!" << endl;
        return false;
    } 
    else if (!isValidAccountNumber(bankAccountID2)){
        cout << "Error: invalid account number!" << endl;
        return false;
    }
    else if(!isValidName(name)){
        cout << "Error: invalid account holders name" << endl;
        return false;
    } 
    else{
        // Convert transaction info to transaction string format
        bankAccountIDString = bankAccountID;
        amountString = amount;
        nameString = name;
        convertNameStringFormat(nameString);
        convertAccountIDStringFormat(bankAccountIDString);
        convertCurrencyStringFormat(amountString);

        // Find User
        if (!user.findAccount(name, bankAccountID)){
            return false;
        }
        // Get user account
        Account& account1 = user.getAccount(name, bankAccountID);

        // Find User
        if (!user.findAccount(name, bankAccountID2)){
            return false;
        }
        // Get user account
        Account& account2 = user.getAccount(name, bankAccountID2);
        
        // Validate User Input For withdrawal
        if(!isValidAmount(amount, user, account1, account2)){
            cout << "Error: Value Error - Not a valid currency value!" << endl;
            return false;
        }
        else{
            transfer(stof(amountString), account1, account2);
            return true;
        }
    }
    return false;
}

bool Transfer::startTransaction(StandardUser& user){
    string name;
    string nameString;
    string bankAccountID;
    string bankAccountID2;
    string bankAccountIDString;
    string bankAccountIDString2;
    string amount;
    string amountString;

    name = user.getName();
    
    // User Inputs
    cout << "Enter account number to transfer from:";
    cin >> bankAccountID;

    cout << "Enter account number to transfer to:";
    cin >> bankAccountID2;

    cout << "Enter amount to transfer:";
    cin >> amount;

    // Validate User Input
    if (!isValidAccountNumber(bankAccountID)){
        cout << "Error: invalid account number!" << endl;
        return false;
    } 
    else if (!isValidAccountNumber(bankAccountID2)){
        cout << "Error: invalid account number!" << endl;
        return false;
    }
    else if(!isValidName(name)){
        cout << "Error: invalid account holders name" << endl;
        return false;
    } 
    else{
        // Convert transaction info to transaction string format
        bankAccountIDString = bankAccountID;
        amountString = amount;
        nameString = name;
        convertNameStringFormat(nameString);
        convertAccountIDStringFormat(bankAccountIDString);
        convertCurrencyStringFormat(amountString);

        // Find User
        if (!user.findAccount(name, bankAccountID)){
            return false;
        }

        // Get user account
        Account& account1 = user.getAccount(name, bankAccountID);

        // Find User
        if (!user.findAccount(name, bankAccountID2)){
            return false;
        }
        
        // Get user account
        Account& account2 = user.getAccount(name, bankAccountID2);
        
        // Validate User Input For withdrawal
        if(!isValidAmount(amount, user, account1, account2)){
            cout << "Error: Value Error - Not a valid currency value!" << endl;
            return false;
        }
        else{
            transfer(stof(amountString), account1, account2);
            return true;
        }
    }
    return false;
}


// TODO: add user parameter and current balance parameter
bool Transfer::isValidAmount(string amount, User& user, Account& account1, Account& account2){
    if (!Transaction::isValidAmount(amount)){
        return false;
    }

    // Convert inputed amount to a float value
    float value;
    string amountWithNoDollarSign;
    if (amount.substr(0,1).compare("$") == 0){
        amountWithNoDollarSign = amount.substr(1);
    }
    else{
        amountWithNoDollarSign = amount;
    }

    // convert to float value
    value = stof(amountWithNoDollarSign);

    if (!user.isAdmin() && value >= 2000){
        return false;
    }
    
    if (value < 0){
        return false;
    }
    
    if (value + account2.getBalance() >= 100000){
        return false;
    }
    
    if (account1.getBalance() - value < 0){
        return false;
    }

    return true;
}
