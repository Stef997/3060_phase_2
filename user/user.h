#ifndef user_h
#define user_h

#include <iostream>
#include <string>

using namespace std;

class User {
    private:
        string* bankAccounts;

    public:
        string* getBankAccounts();
        void addAccount(string account);
        void setBankAccounts(string* accounts);
};

#endif
