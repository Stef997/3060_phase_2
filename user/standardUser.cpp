/*
 *
 *
 */

#include "standardUser.h"

StandardUser::StandardUser(string name) {
    setHoldersName(name);
    Account account = Account();
    account.setPlan("none");
    account.setNumber(1);
    Account defaultAccount = {account};
    bankAccounts = &defaultAccount;
}

string StandardUser::getHoldersName() {
    return holdersName;
}

void StandardUser::setHoldersName(string newName) {
    holdersName = newName;
}
