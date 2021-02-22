#include "withdrawal.h"

Withdrawal::Withdrawal(){

}

bool Withdrawal::startTransaction(/*User user*/)
{
    string name;
    int bankAccountID;
    string bankAccountIDString;
    float amount;

    /* TODO: Implement user and check privilege
    if (user == admin){
        cout << "Enter Account Holder’s Name:";
        cin >> name;
    }
    else{
        name = user.getName();
    }
    */
    
    /* TODO: Add enter user id in test code
    cout << ""
    cin >> bankAccountID
    */

    /* TODO: implement an error handler for int/float values
    cout << "Enter amount to withdraw:";
    cin >> amount;
    */

    // TODO: Implement a way to add 0 preceding id proceeding 5 digits

    /* TODO: Add functionality, fix validity checkers, return types, and add error messages
    if (!isValidAccountNumber(bankAccountIDString)){

    } else if(!isValidName(name)){

    } else if(!isValidAmount(amount)){
        
    } else{
        withdraw(amount)
    }
    */ 
}

//TODO: method should be private
void Withdrawal::withdraw(float amount){
    //Withdraw backend stuff
}

//TODO: change int to string in UML
bool Withdrawal::isValidAccountNumber(string accountNumber){

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

bool Withdrawal::isValidName(string name){
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

// TODO: add user parameter and current balance parameter
bool Withdrawal::isValidAmount(float amount){
    /*if (standard && amount >= 500){
        return false;
    }
    */
    
    if (amount < 0){
        return false;
    }
    
    /*if (amount < balance){
        return false
    }*/

    return true;
}