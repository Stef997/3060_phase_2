/*
* Class containing the account of a user with fields intended for modifications by the ATM system
*/

#include "account.h"

//Instantiates the account with default values
Account::Account() {
    number = "00000";
    balance = 1;
    plan = "none";
    name = "John Doe";
    status = "A";
}

//Sets the account field to match bank account files attributes
Account::Account(string bankAccountLine){
    int bankAccountCharacters = 5;
    int nameCharacters = 20;
    int statusCharacters = 1;
    int balanceCharacters = 8;
    int index = 0;

    number = bankAccountLine.substr(index,index + bankAccountCharacters - 1);
    index += bankAccountCharacters;
    name = bankAccountLine.substr(index, index + nameCharacters - 1);
    index += nameCharacters;
    status = bankAccountLine.substr(nameCharacters, index + statusCharacters - 1);
    index += statusCharacters;
    balance = stof(bankAccountLine.substr(index, index + statusCharacters - 1));

    plan = "none";
}

//Accessor method that returns the bank account ID number
string Account::getNumber() {
    return number;
}

//Accessor method that returns the account holders name
string Account::getName() {
    return name;
}

//Mutator method taking in a new name and sets the account holder’s name to the new name
void Account::setName(string newName) {
    name = newName;
}

//Mutator method accepting a string to change the accounts ID number to the new number
void Account::setNumber(string newNumber) {
    number = newNumber;
}

//Accessor method that returns the balance of the bank account
float Account::getBalance() {
    return balance;
}

//Mutator method which modifies the balance field of the account to reflect the new balance after 
//adding the newBalance value to the previous balance
void Account::addBalance(float amount) {
    balance = balance + amount;
}

//Mutator method which modifies the balance field of the account to reflect the new 
//balance after subtracting the newBalance value to the previous balance
void Account::removeBalance(float amount){
    balance = balance - amount;
}

//Mutator method which switches the disable status of the account
void Account::disable(){
    status = "D";
}

//Accessor method that returns the payment plan of the bank account
string Account::getPlan() {
    return plan;
}

//Mutator method that takes in a string which changes the 
//account’s payment plan to either student (if string value is “SP”) 
//or non-student (if string value is “NP”)
void Account::changePlan() {
    if(plan.compare("SP")){
        plan = "NP";
    }
}
