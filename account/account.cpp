/*
 *
 */

#include "account.h"

int Account::getNumber() {
    return number;
}

void Account::setNumber(int newNumber) {
    number = newNumber;
}

float Account::getBalance() {
    return balance;
}

string Account::getPlan() {
    return plan;
}

void Account::setPlan(string newPlan) {
    plan = newPlan;
}
