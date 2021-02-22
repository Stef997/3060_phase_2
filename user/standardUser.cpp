/*
 *
 *
 */

#include "standardUser.h"

StandardUser::StandardUser(string name) {
    StandardUser::setAccountName(name);
}

string StandardUser::getAccountName() {
    return accountName;
}

void StandardUser::setAccountName(string newName) {
    accountName = newName;
}
