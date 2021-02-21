/*
 * A c++ implementation of a class to represent a user of a
 * bank session within an ATM banking system.
 */

#include "user.h"

//TODO: Create the account class for all bank accounts
//Used to store the accounts being accessed by the
//current user of the session
void User::setBankAccounts(string* accounts) {
    bankAccounts = accounts;
}

//Returns the bank accounts belonging to the user
string* User::getBankAccounts() {
    return bankAccounts;
}

//TODO: Add a bank account to the current user instance (ROUGH version)
void User::addAccount(string account) {
    int currentSize = sizeof(this->bankAccounts)/sizeof(this->bankAccounts) + 1;
    string* newArray = new string[currentSize + 1];
    for(int i = 0; i < currentSize-1; i++) {
        newArray[i] = this->bankAccounts[i];
    }
    newArray[currentSize-1] = account;
    User::setBankAccounts(newArray);
}

//addSessionTransaction is to be moved to BankSession
