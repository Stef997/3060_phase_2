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

bool BankTransaction::noCaseComp(unsigned char a, unsigned char b) {
    return tolower(a) == tolower(b);
}

string BankTransaction::getTransactionName() {
    return name;
}

StandardUser BankTransaction::getUser() {
    return user;
}

bool BankTransaction::startTransaction(User username, string actionName) {
    string loginName;
    bool isDeposited;

    string transactionStr[10] = {"login", "logout",
           "withdrawal", "transfer", "paybill", "deposit",
           "create", "delete", "disable", "changeplan"};

        for(int i = 0; i < 10; i++) {
            if(actionName.length() == transactionStr[i].length()) {
                bool isAction = equal(actionName.begin(), actionName.end(),
                                        transactionStr[i].begin(),
                                        noCaseComp);

                if(isAction) {
                    switch(i) {
                        case 0:
                           loginName = Login().startTransaction();
                           if(loginName != "admin" && loginName != "none") {
                               user = StandardUser();
                               user.setHoldersName(loginName);
                               Account account = Account();
                               account.setNumber(1);
                               account.setPlan("none");
                               user.addAccount(account);
                           } else if (loginName == "admin") {
                               cout << "Admin not implemented" << endl;
                           } else {
                               cout << "Error: Not a valid account name" << endl;
                           }
                           break;
                        case 1:
                           cout << "Logout not implemented" << endl;
                           break;
                        case 2:
                           cout << "Withdrawal not implemented" << endl;
                           break;
                        case 3:
                           cout << "Transfer not implemented" << endl;
                           break;
                        case 4:
                           cout << "Paybill not implemented" << endl;
                           break;
                        case 5:
                           cout << user.getHoldersName() << endl;
                           isDeposited = Deposit().startTransaction(user);
                           break;
                        case 6:
                           cout << "Create not implemented" << endl;
                           break;
                        case 7:
                           cout << "Delete not implemented" << endl;
                           break;
                        case 8:
                           cout << "Disable not implemented" << endl;
                           break;
                        case 9:
                           cout << "Changeplan not implemented" << endl;
                           break;
                    }
                    return true;
                }
            }
        }

    return false;
}
