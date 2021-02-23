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

bool BankTransaction::startTransaction(string name) {
    string transactionStr[10] = {"login", "logout",
           "withdrawal", "transfer", "paybill", "deposit",
           "create", "delete", "disable", "changeplan"};

        for(int i = 0; i < 10; i++) {
            if(name.length() == transactionStr[i].length()) {
                bool isAction = equal(name.begin(), name.end(),
                                        transactionStr[i].begin(),
                                        noCaseComp);

                if(isAction) {
                    switch(i) {
                        case 0:
                           Login().startTransaction();
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
                           cout << "Deposit not implemented" << endl;
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
