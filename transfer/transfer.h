#ifndef transfer_h_
#define transfer_h_

#include <iostream>
#include <string>
#include <regex>

#include "../user/user.h"
#include "../user/adminUser.h"
#include "../user/standardUser.h"
#include "../transaction/transaction.h"

using namespace std;

class Transfer: public Transaction{
    // Methods
    private:
        bool isValidAmount(string amount, User& user, Account& account1, Account& account2);
    public:
        void transfer(float amount, Account& account1, Account& account2);
        bool startTransaction(AdminUser& user);
        bool startTransaction(StandardUser& user);
};

#endif
