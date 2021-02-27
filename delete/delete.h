#ifndef delete_h_
#define delete_h_

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
 * of deleting a bank account
 */

class Delete : public Transaction {
    public:
        void deleteAccount(AdminUser& user, string name, string id);
        bool startTransaction(AdminUser& user);
        bool startTransaction(StandardUser& user);
};

#endif