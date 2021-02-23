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

    } 
    else if (!isValidAccountNumber(bankAccountID2)){

    }
    else if(!isValidName(name)){

    } 
    else if(!isValidAmount(amount)){
        
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
}

// TODO: add user parameter and current balance parameter
bool Transfer::isValidAmount(string amount){
    // Check if number is all integer digits and proper currency float value
    regex regexDigits("^([$]?[0-9]+[.,]?[0-9]{0,2})$", regex::extended);
    if (!regex_match(amount, regexDigits)){
        return false;
    }

    // Check if amount has $ in front and convert to float value
    float value;
    if (amount.substr(0,0).compare("$") == 0){
        value = stof(amount.substr(1));
    }
    else{
        value = stof(amount);
    }

    // Check if amount has specific amount of characters without $ sign
    float value;
    string amountWithNoDollarSign;
    if (amount.substr(0,1).compare("$") == 0){
        amountWithNoDollarSign = amount.substr(1);
    }
    else{
        amountWithNoDollarSign = amount;
    }
    
    int periodPos = amountWithNoDollarSign.find(".");
    int decimalValues = 0;
    
    if (periodPos == -1){
        decimalValues = 3;
    }
    else{
        decimalValues = 3 - (amountWithNoDollarSign.length() - periodPos);
    }

    if (amountWithNoDollarSign.length() + decimalValues > 8 || amountWithNoDollarSign.length() + decimalValues < 1){
        return false;
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