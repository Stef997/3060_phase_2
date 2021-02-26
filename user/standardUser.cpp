/*
 *
 *
 */

#include "standardUser.h"

StandardUser::StandardUser() : User() {
    Account account = Account();
    name = account.getName();
    addAccount(account);

    cout << "Account name: " << account.getName() << endl;
}

string StandardUser::getName() {
    return name;
}

void StandardUser::setName(string newName) {
    name = newName;
}
