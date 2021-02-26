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
        bool findAccount(string name, string id);
        void createAccount(string name, float amount);
        void deleteAccount(string name, string id);
        Account& getAccount(string name, string id);
};

#endif
