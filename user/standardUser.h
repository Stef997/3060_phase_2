#ifndef standarduser_h_
#define standarduser_h_

#include "user.h"
#include <iostream>
#include <string>

using namespace std;

class StandardUser: public User {
    private:
        Account* bankAccounts;
        string holdersName;
    public:
        Account* getBankAccounts();
        void addAccount(Account account);
        void setBankAccounts(Account* accounts);
        StandardUser(string name);
        void setHoldersName(string newName);
        string getHoldersName();
    protected:
};

#endif
