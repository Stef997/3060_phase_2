/*
 *
 */

#include "account.h"

int Account::getNumber() {
    return number;
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
