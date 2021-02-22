#ifndef paybill_h_
#define paybill_h_

#include <iostream>
#include <string>
#include <regex>

#include "../user/user.h"
#include "../user/adminUser.h"
#include "../user/standardUser.h"

using namespace std;

class PayBill {
    // Attributes
    private:

    public:


    // Methods
    private:
        bool isValidName(string name);
        bool isValidAccountNumber(string number);
        bool isValidCompany(string company);
        bool isValidAmount(string amount);
    public:
        PayBill();
        void startTransaction(User user);
        void payBill(float amount); // TODO: This should be changed to private

};

#endif