/*
* A class that inherits the transaction class and performs an atomic operation to transfer funds to a new/separate account
*/

#include "transfer.h"

//Mutator function modifying the account fields of a second account’s balance with passed in 
//account and subtracting the amount from the account balance
void Transfer::transfer(float amount, Account& account1, Account& account2)
{
    account2.removeBalance(amount);
    account1.addBalance(amount);
}

//Start of  the transaction logic where the inputs are prompted for to the user and the 
//transfer function is fired depending on correct inputs
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

//Start of  the transaction logic where the inputs are prompted for to the user and the transfer 
//function is fired depending on correct inputs
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


//Checks the input for correct formatting necessary for actions in the withdrawal class
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
