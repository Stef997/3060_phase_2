#ifndef banktransaction_h_
#define banktransaction_h_

#include "../user/user.h"
#include "../account/account.h"
#include "../bankTransaction/bankTransaction.h"
#include "../login/login.h"
#include <string>

using namespace std;

class BankTransaction {
    private:
        string name;
        static bool noCaseComp(unsigned char a, unsigned char b);
    public:
        BankTransaction();
        BankTransaction(string actionName);
        bool startTransaction(string name);
        string getTransactionName();
};

#endif
