#ifndef paybill_h_
#define paybill_h_

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
        bool isValidAmount(string amount);
    public:
        Transfer();
        void transfer(float amount);
        bool startTransaction(User user);
};

#endif