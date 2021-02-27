/*
* A class representing an atmoic transaction that will modify a users accounts and persist the changes
*/

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
	//Comparison function checking if the name string matches a predefined regex for account names
        bool isValidName(string name);
	//Comparison function checking if the number string matches a predefined regex for account number
        bool isValidAccountNumber(string number);
	//Comparison function checking if the value string matches a predefined regex for value amount strings
        bool isValidAmount(string amount);
	//Converts the account ID into the proper format intended for printout to bank transaction file
        void convertAccountIDStringFormat(string& number);
	//Converts the currency string into the proper format intended for printout to bank transaction file
        void convertCurrencyStringFormat(string& number);
	//Converts the name into the proper format intended for printout to bank transaction file
        void convertNameStringFormat(string& name);
};

#endif
