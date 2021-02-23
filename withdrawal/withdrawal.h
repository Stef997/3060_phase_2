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
        bool isValidAmount(string amount);
    public:
        Withdrawal();
        void withdraw(float amount);
        bool startTransaction(User user);
};

#endif