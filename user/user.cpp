/*
 * A c++ implementation of a class to represent a user of a
 * bank session within an ATM banking system.
 */

#include "user.h"

User::User() {
    Account account = Account();
    addAccount(account);
}

//TODO: Create the account class for all bank accounts
//Used to store the accounts being accessed by the
//current user of the session
void User::setBankAccounts(Account* accounts) {
    bankAccounts = accounts;
}

//Returns the bank accounts belonging to the user
Account* User::getBankAccounts() {
    return bankAccounts;
}

//TODO: Add a bank account to the current user instance (ROUGH version)
void User::addAccount(Account account) {
    int currentSize = sizeof(bankAccounts)/sizeof(bankAccounts) + 1;
    Account* newArray = new Account[currentSize];
    if((currentSize - 1) == 1) {
        Account firstAcc = account;
        Account accArr[] = {account};
        bankAccounts = accArr;
    } else{
        for(int i = 0; i < currentSize-1; i++) {
            newArray[i] = bankAccounts[i];
        }
    }
    newArray[currentSize-1] = account;
    setBankAccounts(newArray);
}

//addSessionTransaction is to be moved to BankSession
