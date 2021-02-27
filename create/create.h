#ifndef create_h_
#define create_h_

#include <iostream>
#include <string>
#include <regex>

#include "../user/user.h"
#include "../user/standardUser.h"
#include "../account/account.h"
#include "../transaction/transaction.h"

using namespace std;

/*
 * This class inherits transaction and is responsible 
 * of creating a new bank account
 */

class Create : public Transaction{
    private:
        bool isValidAmount(string amount);
    public:
        Create();
        void createAccount(AdminUser& user, string name, float amount);
        bool startTransaction(AdminUser& user);
        bool startTransaction(StandardUser& user);
};

#endif