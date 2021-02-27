/*
 * A c++ implementation of a class to represent a user of a
 * bank session within an ATM banking system.
 */

#include "user.h"

/*
void User::setBankAccounts(Account* accounts) {
    bankAccounts = accounts;
}
*/

//Accessor method that returns a list of Account objects the user owns
vector<Account> User::getBankAccounts() {
    return bankAccounts;
}

//Mutator method that adds the new account to a list of Account objects the user owns
void User::addAccount(Account account) {
    /*
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
    */

   bankAccounts.push_back(account);
}

//Returns whether the admin field has been set
bool User::isAdmin(){
    return false;
}

//Returns whether the account belongs to the specific user by comparing the user fields with parameters
bool User::findAccount(string name, string id){
    for (int i = 0; i < bankAccounts.size(); i++){
        if (bankAccounts[i].getName().compare(name) == 0 && bankAccounts[i].getNumber().compare(id) == 0){
            return true;
        }
    }
    return false;
}

//Delete the account specified by parameter values
void User::deleteAccount(string name, string id){
    for (int i = 0; i < bankAccounts.size(); i++){
        if (bankAccounts[i].getName().compare(name) == 0 && bankAccounts[i].getNumber().compare(id) == 0){
            bankAccounts.erase(bankAccounts.begin() + i);
        }
    }
}

//Instantiate an account based on the parameter values
void User::createAccount(string name, float amount){
    Account account = Account();
    bankAccounts.push_back(account);
}

//Return the account by reference of the requested account with the same ID belonging to the user
Account& User::getAccount(string name, string id){
    for (int i = 0; i < bankAccounts.size(); i++){
        if (bankAccounts[i].getName().compare(name) == 0 && bankAccounts[i].getNumber().compare(id) == 0){
            return bankAccounts[i];
        }
    }
}
