#ifndef banktransaction_h_
#define banktransaction_h_

#include "../user/user.h"
#include "../account/account.h"
#include "../bankTransaction/bankTransaction.h"
#include "../login/login.h"
#include "../user/user.h"
#include "../user/standardUser.h"
#include "../user/adminUser.h"
#include <string>

using namespace std;

class BankTransaction {
    private:
        User user;
        string name;
        static bool noCaseComp(unsigned char a, unsigned char b);
    public:
        BankTransaction();
        BankTransaction(string actionName);
        bool startTransaction(User username, string actionName);
        string getTransactionName();
};

#endif
