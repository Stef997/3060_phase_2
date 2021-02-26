#ifndef login_h_
#define login_h_

#include <iostream>
#include <string>
#include <regex>
#include "../user/user.h"
#include "../user/standardUser.h"
#include "../user/adminUser.h"
#include "../transaction/transaction.h"

using namespace std;

class Login: public Transaction {
    private:
        static bool noCaseComp(unsigned char a, unsigned char b);
        bool isAdmin(string session);
    public:
        string userVals[2];
        Login();
        bool startTransaction(User user);
        string* login();

};

#endif
