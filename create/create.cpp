#include "create.h"

Create::Create(){

}

bool Create::startTransaction(User& user){
    string name;
    string nameString;
    string amount;
    string amountString;
    Account account;

    // Check If User Is Admin Session Before Proceeding
    if (!user.isAdmin()){
        cout << "ERROR: Transaction Error - Delete transaction cannot be accessed from a standard account" << endl;
        return false;
    }

    // User Input
    cout << "Enter Account Holder’s Name:";
    cin >> name;

    cout << "Enter Initial Balance:";
    cin >> amount;

     // Validate User Input For Account
    if(!isValidName(name)){
        //Output error message indicating invalid info
        cout << "Error: Account holders name is invalid!" << endl;
        return false;
    } else{
        // Convert transaction info to transaction string format
        nameString = name;
        convertNameStringFormat(nameString);
    }

    // Validate User Input For Create Account
    if(!isValidAmount(amount)){
        cout << "Error: invalid value amount!" << endl;
        return false;
    } else{
        // Create Account
        createAccount(user, name, stof(amountString));
    }
}

void Create::createAccount(User& user, string name, float amount){
    user.createAccount(name, amount);
}

bool Create::isValidAmount(string amount){
    if (!Transaction::isValidAmount(amount)){
        return false;
    }

    // Convert inputted amount to a float value
    float value;
    string amountWithNoDollarSign;

    //Check for dollar sign within amount string
    if (amount.substr(0,1).compare("$") == 0){
        amountWithNoDollarSign = amount.substr(1);
    }
    else{
        amountWithNoDollarSign = amount;
    }

    // convert to float value
    value = stof(amountWithNoDollarSign);
    
    //Check for negative values
    if (value < 0){
        return false;
    }
    
    //Check for the value amount on deposits
    if (value >= 10000){
        return false;
    }

    return true;
}