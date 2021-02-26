#ifndef transaction_h_
#define transaction_h_

#include <iostream>
#include <string>
#include <regex>

#include "../user/user.h"
#include "../user/adminUser.h"
#include "../user/standardUser.h"

using namespace std;

class Transaction {
    protected:
    public:
        bool isValidName(string name);
        bool isValidAccountNumber(string number);
        bool isValidAmount(string amount);
        virtual bool startTransaction(User user) = 0;
        void convertAccountIDStringFormat(string& number);
        void convertCurrencyStringFormat(string& number);
        void convertNameStringFormat(string& name);
};

#endif
