#include <iostream>
#include <string>
#include <regex>
#include "changePlan.h"

using namespace std;

class ChangePlan {
    public: ChangePlan(){

    }

bool ChangePlan::isValidAccountNumber(string accountNumber){

    // Check if number is not null
    if (accountNumber.empty()){
        return false;
    }

    // Check if number is 1-5 characters long
    if (accountNumber.length() > 5  accountNumber.length() < 1){
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


bool ChangePlan::startTransaction(StandardUser user) {
    string holdersName;
    string accountNum;
    float depositAmount;

    Account* accounts = user.getBankAccounts();
    cout << "Enter account number: ";
    cin >> accountNum;
    if(isValidAccountNumber(accountNum, accounts)){
        cout << "Enter deposit amount: ";
        cin >> depositAmount;
        int intAccNum = stoi(accountNum);
        accounts[intAccNum].addBalance(depositAmount);
        return true;
    } 
    return false;
}

 private: bool isValidName(string name){
             // Check if name is not null or empty string
        if (name.empty()  name.compare("") == 0){
            return false;
        }

};


void Account::setPlan(string newPlan) {
    plan = newPlan;
}
