/*
 *
 *
 */

#include "session.h"

bool Session::noCaseComp(unsigned char a, unsigned char b) {
    return tolower(a) == tolower(b);
}

void Session::promptTransaction() {
    string actionName;
    string username;
    bool isAdmin;
    bool isStandard;

    string sessionTypes[2] = {"admin", "standard"};

    string transactionStr[10] = {"login", "logout",
           "withdrawal", "transfer", "paybill", "deposit",
           "create", "delete", "disable", "changeplan"};

    string newUser[2]; 

    while(actionName != "logout") {
        cout << "Enter Transaction: ";
        cin >> actionName;

        for(int i = 0; i < 10; i++) {
            if(actionName.length() == transactionStr[i].length()) {
                bool isAction = equal(actionName.begin(), actionName.end(),
                                        transactionStr[i].begin(),
                                        noCaseComp);
                if(isAction) {
                    switch(i) {
                        case 0:
                           string* newUser;
                           newUser = Login().login();
                           isAdmin = equal(newUser[0].begin(), newUser[0].end(), sessionTypes[0].begin(), noCaseComp);
                           isStandard = equal(newUser[0].begin(), newUser[0].end(), sessionTypes[1].begin(), noCaseComp);
                           username = newUser[1];
                           if(isAdmin) {
                               if(isAdmin) {
                                   AdminUser admin = AdminUser();
                                   admin.setAdmin();
                                   adminUser = admin;
                                   isAdminSession = true;
                               }
                           } else if (isStandard) {
                               if(isStandard) {
                                   StandardUser standard = StandardUser(username);
                                   standardUser = standard;
                                   isAdminSession = false;
                               }
                           }
                           break;
                        case 1:
                           cout << "Logout not implemented" << endl;
                           break;
                        case 2:
                           if(isAdminSession) {
                               if(adminUser.isAdmin() == true) {
                                   Withdrawal().startTransaction(adminUser);
                               }
                           } else {
                               Withdrawal().startTransaction(standardUser);
                           }
                           break;
                        case 3:
                           cout << "Transfer not implemented" << endl;
                           break;
                        case 4:
                           if(isAdminSession) {
                               if(adminUser.isAdmin() == true) {
                                   PayBill().startTransaction(adminUser);
                               }
                           } else {
                               PayBill().startTransaction(standardUser);
                           }
                           cout << standardUser.getBankAccounts()[0].getBalance();
                           break;
                        case 5:
                           if(isAdminSession) {
                               if(adminUser.isAdmin() == true) {
                                   Deposit().startTransaction(adminUser);
                               }
                           } else {
                               Deposit().startTransaction(standardUser);
                           }
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
                }
            }
        }        
    }
}

Session::Session() {
    promptTransaction();
}
