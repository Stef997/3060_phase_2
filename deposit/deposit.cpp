/*
 *
 *
 */

#include "deposit.h"

bool Deposit::startTransaction(User user) {
    string name;
    string nameString;
    string bankAccountID;
    string bankAccountIDString;
    string amount;
    string amountString;

    /* TODO: Implement user and check privilege
    if (user == admin){
        cout << "Enter Account Holder’s Name:";
        cin >> name;
    }
    else{
        name = user.getName();
    }
    */
    
    // TODO: Add enter user id in test code
    // User Input
    cout << "Enter account number to pay bill from:";
    cin >> bankAccountID;

    cout << "Enter amount to deposit:";
    cin >> amount;
    
    // Validate User Input
    if (!isValidAccountNumber(bankAccountID)){

    } else if(!isValidName(name)){

    } else if(!isValidAmount(amount)){
        
    } else{
        deposit(stof(amount));

        // Convert transaction info to transaction string format
        bankAccountIDString = bankAccountID;
        amountString = amount;
        convertAccountIDStringFormat(bankAccountIDString);
        convertCurrencyStringFormat(amountString);
    }
}


// TODO: add user parameter and current balance parameter
bool Deposit::isValidAmount(string amount){
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
    
    if (value < 0){
        return false;
    }
    
    /*if (value < balance){
        return false
    }*/

    return true;
}