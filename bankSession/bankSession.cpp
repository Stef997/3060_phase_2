/*
 *
 *
 */

#include "bankSession.h"

void BankSession::promptTransaction() {
    string actionName;
    cout << "Enter Transaction: " << endl;
    cin >> actionName;
    BankTransaction transaction = BankTransaction(actionName);
    transaction.startTransaction(user);
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
