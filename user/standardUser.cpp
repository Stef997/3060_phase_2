/*
 *
 *
 */

#include "standardUser.h"

StandardUser::StandardUser() {
    string name;
    cout << "Enter account name: ";
    cin >> name;
    StandardUser::setAccountName(name);
}

string StandardUser::getAccountName() {
    return accountName;
}

void StandardUser::setAccountName(string newName) {
    accountName = newName;
}
