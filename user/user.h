#ifndef user_h_
#define user_h_

#include <iostream>
#include <string>
#include "../account/account.h"

using namespace std;

class User: public Account {
    private:
        /*Account* bankAccounts;*/
        vector<Account> bankAccounts;

    public:
        User();
        vector<Account> getBankAccounts();
        void addAccount(Account account);
        /*void setBankAccounts(Account* accounts);*/
        bool isAdmin();
        Account findAccount(string name, string id);
};

#endif
