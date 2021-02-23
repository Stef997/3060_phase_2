#ifndef deposit_h_
#define deposit_h_

#include <iostream>
#include <string>
#include "../user/user.h"
#include "../user/standardUser.h"
#include "../account/account.h"

using namespace std;

class Deposit {
    private:
        long amount;
    public:
        bool startTransaction(StandardUser user);
        void deposit(float value);
        bool isValidAccountNumber(string number, Account* accounts);
        bool isValidName(string name);
        bool isValidAmount(float amount);
    protected:
};

#endif
