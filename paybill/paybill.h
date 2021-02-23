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

class PayBill: public Transaction{
    // Methods
    private:
        bool isValidCompany(string company);
        bool isValidAmount(string amount);
    public:
        PayBill();
        bool startTransaction(User user);
        void payBill(float amount); // TODO: This should be changed to private
};

#endif