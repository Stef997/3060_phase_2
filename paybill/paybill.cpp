#include "paybill.h"

PayBill::PayBill(){

}

void PayBill::startTransaction(/*User user*/)
{
    string name;
    int bankAccountID;
    string bankAccountIDString;
    string companyName;
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

    /* TODO: Add enter user company name
    cout << "Enter the company to pay the bill to"
    cin >> companyName
    */

    /* TODO: implement an error handler for int/float values
    cout << "Enter amount to pay:";
    cin >> amount;
    */

    // TODO: Implement a way to add 0 preceding id proceeding 5 digits

    /* TODO: Add functionality, fix validity checkers, return types, and add error messages
    if (!isValidAccountNumber(bankAccountIDString)){

    } else if(!isValidName(name)){

    } else if(!isValidCompany(companyName)){

    } else if(!isValidAmount(amount)){
        
    } else{
        payBill(amount)
    }
    */ 
}

//TODO: method should be private
void PayBill::payBill(float amount){
    //PayBill backend stuff
}

// TODO: Implement a company txt file and have it read over it to compare
bool PayBill::isValidCompany(string company){
    return company.compare("EC") == 0 || company.compare("CQ") == 0 || company.compare("FI") == 0;
}

//TODO: change int to string in UML
bool PayBill::isValidAccountNumber(string accountNumber){

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

bool PayBill::isValidName(string name){
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
bool PayBill::isValidAmount(float amount){
    /*if (standard && amount >= 2000){
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