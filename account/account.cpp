/*
 *
 */

#include "account.h"

Account::Account() {
    number = "00000";
    balance = 0;
    plan = "none";
}

string Account::getNumber() {
    return number;
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

string Account::getPlan() {
    return plan;
}

void Account::setPlan(string newPlan) {
    plan = newPlan;
}
