/*
 *
 *
 */

#include "standardUser.h"

//Constructor that takes in a string of the account owner’s name and 
//initializes the StandardUser object to default values
StandardUser::StandardUser() : User() {
    name = "none";
    Account account = Account();
    account.setName("none");
    addAccount(account);
}

//Constructor that takes in a string of the account owner’s name and initializes the 
//StandardUser object to parameter values
StandardUser::StandardUser(string initName) : User() {
    name = initName;
    Account account = Account();
    account.setName(initName);
    addAccount(account);
}

//Accessor method that returns the account owner’s name
string StandardUser::getName() {
    return name;
}

//Mutator method that modifies the account owner’s name
void StandardUser::setName(string newName) {
    name = newName;
}
