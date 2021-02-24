#include <iostream>
#include <string>
#include <regex>
#include "disable.h"

using namespace std;

class Disable {
    public: Disable(){

    }
    private: bool isDisabled(StandardUser user){
      if ( user == false){
          cout<<"The user does not exist anymore"<<endl;
      } else {
          cout << " user still exists" <<endl;
      }

    }

bool Disable::isValidAccountNumber(string accountNumber){

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

    return true;
} 


bool Disable::startTransaction(StandardUser user) {
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