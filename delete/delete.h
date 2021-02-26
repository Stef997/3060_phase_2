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

class Delete : public Transaction {
    public:
        Delete();
        void deleteAccount(string name, string id);
        bool startTransaction(User& user);
};

#endif