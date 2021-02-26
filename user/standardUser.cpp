/*
 *
 *
 */

#include "standardUser.h"

StandardUser::StandardUser() : User() {
    name = "none";
    Account account = Account();
    account.setName("none");
    addAccount(account);
}

StandardUser::StandardUser(string initName) : User() {
    name = initName;
    Account account = Account();
    account.setName(initName);
    addAccount(account);
}

string StandardUser::getName() {
    return name;
}

void StandardUser::setName(string newName) {
    name = newName;
}
