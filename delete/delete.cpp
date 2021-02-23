#include "delete.h"

Delete::Delete(){

}

bool Delete::startTransaction(StandardUser user){
    string name;
    string accountNum;

    Account* accounts = user.getBankAccounts();
    cout << "Enter account holder's name: ";
    cin >> name;

    cout << "Enter The Account Number";
    cin >> accountNum;

    if (!isValidAccountNumber(accountNum)){
        cout << "Error";
    } else if(!isValidName(name)){
        cout << "Error";
    }  
    else{
        delete(accounts);
    }

}

void Delete::delete(int account){
    //Withdraw backend stuff
}

bool Delete::isValidName(string name){
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

bool Delete::isValidAccountNumber(string accountNumber){

    // Check if number is not null
    if (accountNumber.empty()){
        return false;
    }

    // Check if number is 1-5 characters long
    if (accountNumber.length() > 5 || accountNumber.length() < 1){
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