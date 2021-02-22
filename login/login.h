#ifndef login_h_
#define login_h_

#include <iostream>
#include <string>
#include <regex>
#include "../user/user.h"
#include "../user/standardUser.h"
#include "../user/adminUser.h"

using namespace std;

class Login : public User {
    private:
        bool isValidName(string name);
        static bool noCaseComp(unsigned char a, unsigned char b);
        bool isAdmin(string session);
    public:
        User startTransaction();
        void login(string sessionType);

};

#endif
