#ifndef withdrawal_h_
#define withdrawal_h_

#include <iostream>
#include <string>
#include <regex>

using namespace std;

class Withdrawal {
    // Attributes
    private:

    public:

    // Methods
    private:
        bool isValidName(string name);
        bool isValidAccountNumber(string number);
        bool isValidAmount(float amount);
    public:
        Withdrawal();
        void withdraw(float amount);
        bool startTransaction();
};

#endif