#ifndef banksession_h_
#define banksession_h_

#include <iostream>
#include <string>

#include "../user/user.h"
#include "../user/adminUser.h"
#include "../user/standardUser.h"
#include "../transaction/transaction.h"
#include "../login/login.h"
#include "../deposit/deposit.h"
#include "../withdrawal/withdrawal.h"
#include "../paybill/paybill.h"
#include "../transfer/transfer.h"
#include "../ChangePlan/changePlan.h"

using namespace std;

class Session: public User {
    private:
        AdminUser adminUser;
        StandardUser standardUser;
        bool isAdminSession;
    public:
        Session();
        static bool noCaseComp(unsigned char a, unsigned char b);
        void promptTransaction();
};

#endif
