#ifndef banksession_h_
#define banksession_h_

#include <iostream>
#include <string>
#include "../user/user.h"
#include "../user/adminUser.h"
#include "../user/standardUser.h"
#include "../bankTransaction/bankTransaction.h"

using namespace std;

class BankSession: public BankTransaction, public User {
    private:
        User user;
    public:
        void promptTransaction();
        BankSession();
        bool checkPrivilege();
        void setUser(User user);
        User getUser();
};

#endif
