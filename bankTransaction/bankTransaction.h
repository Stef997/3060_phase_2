#ifndef banktransaction_h_
#define banktransaction_h_

#include "../user/user.h"
#include <string>

using namespace std;

class BankTransaction {
    private:
        string name;
    public:
        BankTransaction();
        BankTransaction(string actionName);
        bool startTransaction(User user);
};

#endif
