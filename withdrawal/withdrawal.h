#ifndef withdrawal_h_
#define withdrawal_h_

#include <iostream>
#include <string>
#include <regex>

#include "../user/user.h"
#include "../user/adminUser.h"
#include "../user/standardUser.h"
#include "../transaction/transaction.h"

using namespace std;

class Withdrawal: public Transaction{
    // Methods
    private:
        bool isValidAmount(string amount, User& user, Account& account);
    public:
        void withdraw(float amount, Account& account);
        bool startTransaction(User& user);
};

#endif
