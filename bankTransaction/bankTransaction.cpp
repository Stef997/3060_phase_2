/*
 *
 *
 */

#include "bankTransaction.h"

BankTransaction::BankTransaction() {
    name = "none";
}

BankTransaction::BankTransaction(string actionName) {
    name = actionName;
}

bool BankTransaction::startTransaction(User user) {
    //TODO: Statement (Switch?) to control which transaction
    //is called and pass the current user calling it
    return false;
}
