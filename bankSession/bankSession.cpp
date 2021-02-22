/*
 *
 *
 */

#include "bankSession.h"

void BankSession::promptTransaction() {
    string actionName;
    while(actionName != "logout") {
        cout << "Enter Transaction: ";
        cin >> actionName;
        BankTransaction transaction = BankTransaction(actionName);
        transaction.startTransaction(User(), transaction.getTransactionName());
        if(transaction.getTransactionName() == "login") {
            user = transaction.getUser();
        }
    }
}

BankSession::BankSession() {
    promptTransaction();
}

bool BankSession::checkPrivilege() {
    if(typeid(user).name() == typeid(AdminUser).name()) {
        return true;
    } else {
        return false;
    }
}

void BankSession::setUser(User newUser) {
    user = newUser;
}

User BankSession::getUser() {
    return user;
}
