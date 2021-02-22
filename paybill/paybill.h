#ifndef paybill_h_
#define paybill_h_

#include <iostream>
#include <string>
#include <regex>

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
        bool isValidAmount(float amount);
    public:
        PayBill();
        void startTransaction();
        void payBill(float amount); // TODO: This should be changed to private

};

#endif