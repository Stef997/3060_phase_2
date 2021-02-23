#include "withdrawal.h"

Withdrawal::Withdrawal(){

}

bool Withdrawal::startTransaction(User user)
{
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

    cout << "Enter amount to withdraw:";
    cin >> amount;
    
    // Validate User Input
    if (!isValidAccountNumber(bankAccountID)){

    } else if(!isValidName(name)){

    } else if(!isValidAmount(amount)){
        
    } else{
        withdraw(stof(amount));

        // Convert transaction info to transaction string format
        bankAccountIDString = bankAccountID;
        amountString = amount;
        convertAccountIDStringFormat(bankAccountIDString);
        convertCurrencyStringFormat(amountString);
    }
}

//TODO: method should be private
void Withdrawal::withdraw(float amount){
    //Withdraw backend stuff
}

// TODO: add user parameter and current balance parameter
bool Withdrawal::isValidAmount(string amount){
    // Check if number is all integer digits and proper currency float value
    regex regexDigits("^([$]?[0-9]+[.,]?[0-9]{0,2})$", regex::extended);
    if (!regex_match(amount, regexDigits)){
        return false;
    }

    // Check if amount has $ in front and convert to float value
    float value;
    if (amount.substr(0,1).compare("$") == 0){
        value = stof(amount.substr(1));
    }
    else{
        value = stof(amount);
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