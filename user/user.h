#ifndef user_h_
#define user_h_

#include <iostream>
#include <string>
#include "../account/account.h"

using namespace std;

class User: public Account {
    private:
        Account* bankAccounts;

    public:
        Account* getBankAccounts();
        void addAccount(Account account);
        void setBankAccounts(Account* accounts);
};

#endif
