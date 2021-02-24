#include "transfer.h"

Transfer::Transfer(){

}

void Transfer::transfer(float amount)
{

}

bool Transfer::startTransaction(User user){
    string name;
    string nameString;
    string bankAccountID;
    string bankAccountID2;
    string bankAccountIDString;
    string bankAccountIDString2;
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
    else if(!isValidAmount(amount)){
        cout << "Error: invalid value amount!" << endl;
        return false;
    } 
    else{
        transfer(stof(amount));

        // Convert transaction info to transaction string format
        bankAccountIDString = bankAccountID;
        bankAccountIDString2 = bankAccountID2;
        amountString = amount;
        convertAccountIDStringFormat(bankAccountIDString);
        convertAccountIDStringFormat(bankAccountIDString2);
        convertCurrencyStringFormat(amountString);
    }
    return true;
}

// TODO: add user parameter and current balance parameter
bool Transfer::isValidAmount(string amount){
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
    /*if (standard && value >= 2000){
        return false;
    }
    */
    
    if (value < 0){
        return false;
    }
    
    /*if (value < balance){
        return false
    }*/

    return true;
}
