#include "transaction.h"

//TODO: change int to string in UML
bool Transaction::isValidAccountNumber(string accountNumber){

    // Check if number is not null
    if (accountNumber.empty()){
        return false;
    }

    // Check if number is 5 characters long
    if (accountNumber.length() != 5){
        return false;
    }

    // Check if number is all integer digits
    regex regexDigits("[0-9]+");
    if (!regex_match(accountNumber, regexDigits)){
        return false;
    }

    // TODO: Check number exist in the data base

    return true;
}

bool Transaction::isValidName(string name){
    // Check if name is not null or empty string
    if (name.empty() || name.compare("") == 0){
        return false;
    }

    // Check if name is at most 20 characters long and at least 1 character long
    if (name.length() > 20){
        return false;
    }

    // Check if name does not contain digits or illegal characters
    regex regexName("[^\\t\\n\\r\\f\\v0-9\\[\\]!@#$%^&*()_+{}|\\:;\"\'<,>.?/~`]+");
    if (!regex_match(name, regexName)){
        return false;
    }

    return true;
}

void Transaction::convertAccountIDStringFormat(string& number){
    while(number.length() < 5)
    {
        number.insert(0, "0");
    }
}

void Transaction::convertCurrencyStringFormat(string& number){
    int periodPos = number.find(".");
    int decimalZeros;
    
    // Check if there's a dollar sign in front and remove it
    cout <<number.substr(0,0)<<endl;
    if (number.substr(0,1).compare("$") == 0){
        number.erase(0);
    }
    
    // add decimal if no decimal and find 0s up to 2 decimal places
    if (periodPos == -1){
        decimalZeros = 2;
        number.insert(number.length(), ".");
    }else {
        decimalZeros = number.length() - periodPos;
    }
    
    // Add zeros after decimal
    if(decimalZeros <= 2){
        for(int i = 0; i < decimalZeros; i++){
            number.insert(number.length(), "0");
        }
    }
    
    // Add zeros to the front
    for (int i = number.length(); i < 8; i++){
        number.insert(0, "0");
    }
}

// TODO: add user parameter and current balance parameter
bool Transaction::isValidAmount(string amount){
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

    return true;
}