/*
 *
 *
 */

#include "deposit.h"

bool Deposit::startTransaction(StandardUser user) {
    string holdersName;
    int accountNum;
    float depositAmount;

    Account* accounts = user.getBankAccounts();

    cout << "Enter account number: ";
    cin >> accountNum;
    if(isValidAccountNumber(accountNum, accounts)){
        cout << "Enter deposit amount: ";
        cin >> depositAmount;
        accounts[accountNum].addBalance(depositAmount);
        cout << accounts[accountNum].getBalance();
        return true;
    } 

    return false;
}

bool Deposit::isValidAccountNumber(int number, Account* accounts) {
    int accountSize = sizeof(accounts)/sizeof(Account);
    for(int i = 0; i <= accountSize; i++) {
        cout << accounts[i].getNumber() << endl;
    }
    return false;
}
