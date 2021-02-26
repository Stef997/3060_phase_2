/*
 *
 */

#include "account.h"

Account::Account() {
    number = "00000";
    balance = 0;
    plan = "none";
    name = "John Doe";
    status = "A";
}

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

string Account::getNumber() {
    return number;
}

string Account::getName() {
    return name;
}

void Account::setNumber(string newNumber) {
    number = newNumber;
}

float Account::getBalance() {
    return balance;
}

void Account::addBalance(float amount) {
    balance = balance + amount;
}

void Account::removeBalance(float amount){
    balance = balance - amount;
}

string Account::getPlan() {
    return plan;
}

void Account::changePlan() {
    if(plan.compare("SP")){
        plan = "NP";
    }
}
