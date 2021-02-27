#ifndef disable_h_
#define disable_h_

#include <iostream>
#include <string>
#include <regex>

#include "../user/user.h"
#include "../user/standardUser.h"
#include "../account/account.h"
#include "../transaction/transaction.h"

using namespace std;

class Disable : public Transaction {
    public:
        Disable();
        void disableAccount(Account& account);
        bool startTransaction(AdminUser& user);
        bool startTransaction(StandardUser& user);
};

#endif