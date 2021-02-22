#ifndef paybill_h_
#define paybill_h_

#include <iostream>
#include <string>
#include <regex>

using namespace std;

class Transfer {
    // Attributes
    private:

    public:

    // Methods
    private:
        bool isValidName(string name);
        bool isValidAccountNumber(string number);
        bool isValidAmount(float amount);
    public:
        Transfer();
        float transfer();
        bool startTransaction();
};

#endif