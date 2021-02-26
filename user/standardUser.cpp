/*
 *
 *
 */

#include "standardUser.h"

StandardUser::StandardUser() : User() {
    Account account = Account();
    account.setName(name);
    addAccount(account);
    cout << "Account name: " << account.getName() << endl;
}

string StandardUser::getName() {
    return name;
}

void StandardUser::setName(string newName) {
    name = newName;
}
