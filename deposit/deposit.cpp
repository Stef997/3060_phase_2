/*
 *
 *
 */

#include "deposit.h"

bool Deposit::startTransaction(StandardUser user) {
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

bool Deposit::isValidAccountNumber(string number, Account* accounts) {
    int accountSize = sizeof(accounts)/sizeof(Account);
    for(int i = 0; i <= accountSize; i++) {
        if(stoi(number) == stoi(accounts->getNumber())) {
            return true;
        }
    }
    return false;
}
