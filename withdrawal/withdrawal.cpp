#include "withdrawal.h"

//Start of  the transaction logic where the inputs are prompted for to the user and the 
//withdraw function is fired depending on correct inputs
bool Withdrawal::startTransaction(AdminUser& user) {
    string name;
    string nameString;
    string bankAccountID;
    string bankAccountIDString;
    string amount;
    string amountString;

    cout << "Enter Account Holder’s Name:";
    cin >> name;
    
    // TODO: Add enter user id in test code
    // User Input
    cout << "Enter account number to withdraw from:";
    cin >> bankAccountID;

    cout << "Enter amount to withdraw:";
    cin >> amount;
    
    // Validate User Input
    if (!isValidAccountNumber(bankAccountID)){
        cout << "Error: Value Error - Account number does not exist!" << endl;
    } else if(!isValidName(name)){
        cout << "Error: Input Error - Account name does not belong to user!" << endl;
        return false;
    } else{
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
        Account& account = user.getAccount(name, bankAccountID);
        
        // Validate User Input For withdrawal
        if(!isValidAmount(amount, user, account)){
            cout << "Error: Value Error - Not a valid currency value!" << endl;
            return false;
        }
        else{
            withdraw(stof(amountString), account);
            return true;
        }
    }
    return false;
}

//Start of the transaction logic where the inputs are prompted for to the user and
//the withdraw function is fired depending on correct inputs
bool Withdrawal::startTransaction(StandardUser& user) {
    string name;
    string nameString;
    string bankAccountID;
    string bankAccountIDString;
    string amount;
    string amountString;

    name = user.getName();

    // TODO: Add enter user id in test code
    // User Input
    cout << "Enter account number to withdraw from:";
    cin >> bankAccountID;

    cout << "Enter amount to withdraw:";
    cin >> amount;
    
    // Validate User Input
    if (!isValidAccountNumber(bankAccountID)){
        cout << "Error: Value Error - Account number does not exist!" << endl;
    } else if(!isValidName(name)){
        cout << "Error: Input Error - Account name does not belong to user!" << endl;
        return false;
    } else{
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
        Account& account = user.getAccount(name, bankAccountID);
        
        // Validate User Input For withdrawal
        if(!isValidAmount(amount, user, account)){
            cout << "Error: Value Error - Not a valid currency value!" << endl;
            return false;
        }
        else{
            withdraw(stof(amountString), account);
            return true;
        }
    }
    return false;
}

//Mutator function modifying the account fields of the passed in account and 
//subtracting the amount from the account balance
void Withdrawal::withdraw(float amount, Account& account){
    account.removeBalance(amount);
}

//Checks the input for correct formatting necessary for actions in the withdrawal class
bool Withdrawal::isValidAmount(string amount, User& user, Account& account){

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

    // Check if value is within boundaries 
    if (!user.isAdmin() && value >= 2000){
        return false;
    }
    
    if (value < 0){
        return false;
    }

    if (value >= 100000){
        return false;
    }
    
    if (account.getBalance() - value < 0){
        return false;
    }

    return true;
}
