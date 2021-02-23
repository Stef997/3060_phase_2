#include <iostream>
#include <string>
#include <regex>

#include "../user/user.h"
#include "../user/adminUser.h"
#include "../user/standardUser.h"

using namespace std;

class Transaction {
    protected:
        bool isValidName(string name);
        bool isValidAccountNumber(string number);
    public:
        virtual bool startTransaction(User user) = 0;
        void convertAccountIDStringFormat(string& number);
        void convertCurrencyStringFormat(string& number);
};