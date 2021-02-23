#ifndef paybill_h_
#define paybill_h_

#include <iostream>
#include <string>
#include <regex>

#include "../user/user.h"
#include "../user/adminUser.h"
#include "../user/standardUser.h"

using namespace std;

class Transfer {
    // Attributes
    private:

    public:

    // Methods
    private:
        bool isValidName(string name);
        bool isValidAccountNumber(string number);
        bool isValidAmount(string amount);
    public:
        Transfer();
        void transfer(float amount);
        bool startTransaction(User user);
        void convertAccountIDStringFormat(string& number);
        void convertCurrencyStringFormat(string& number);
};

#endif