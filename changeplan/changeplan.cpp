#include <iostream>
#include <string>
#include <regex>
#include "changeplan.h"

using namespace std;

bool ChangePlan::startTransaction(User user) {
    string holdersName;
    string accountNum;
    float depositAmount;

    //TODO: Retrieve account for user

    cout << "Enter account number: ";
    cin >> accountNum;
    if(isValidAccountNumber(accountNum)){
        cout << "Enter deposit amount: ";
        cin >> depositAmount;
        int intAccNum = stoi(accountNum);
        //accounts[intAccNum].addBalance(depositAmount);
        return true;
    } 
    return false;
}
