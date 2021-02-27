#ifndef changePlan_h_
#define changePlan_h_

#include <iostream>
#include <string>
#include <regex>
#include "../user/user.h"
#include "../user/standardUser.h"
#include "../account/account.h"
#include "../transaction/transaction.h"

using namespace std;

class ChangePlan : public Transaction{
    private:
    public:
    private:
        bool startTransaction(AdminUser& user);
        bool startTransaction(StandardUser& user);
        void setPlan(Account& account);
};

#endif
