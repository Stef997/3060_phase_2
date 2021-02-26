#ifndef deposit_h_
#define deposit_h_

#include <iostream>
#include <string>
#include "../user/user.h"
#include "../user/standardUser.h"
#include "../account/account.h"
#include "../transaction/transaction.h"

using namespace std;

class Deposit: public Transaction {
    private:
        bool isValidAmount(string amount, Account account);
    public:
        bool startTransaction(User user);
        bool startTransaction(AdminUser& user);
        bool startTransaction(StandardUser& user);
        void deposit(float value, Account& account);
};

#endif
