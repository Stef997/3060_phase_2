#include "paybill.h"

PayBill::PayBill(){

}

void PayBill::startTransaction(User user)
{
    string name;
    string bankAccountID;
    string bankAccountIDString;
    string companyName;
    string amount;

    /* TODO: Implement user and check privilege
    if (user == admin){
        cout << "Enter Account Holder’s Name:";
        cin >> name;
    }
    else{
        name = user.getName();
    }
    */
    
    cout << "Enter account number to pay bill from:";
    cin >> bankAccountID;

    cout << "Enter the company to pay the bill to:";
    cin >> companyName;

    cout << "Enter amount to pay:";
    cin >> amount;

    // TODO: Implement a way to add 0 preceding id proceeding 5 digits and account number

    if (!isValidAccountNumber(bankAccountIDString)){
        cout << "" << endl;
    } else if(!isValidName(name)){

    } else if(!isValidCompany(companyName)){
        cout << "" << endl;
    } else if(!isValidAmount(amount)){
        cout << "ERROR: Value Error - Account name does not exist!" << endl;
    } else{
        payBill(stof(amount));
    }
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
bool PayBill::isValidAmount(string amount){

    // Check if number is all integer digits and proper currency float value
    regex regexDigits("^([$]?[0-9]+[.,]?[0-9]{0,2})$");
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