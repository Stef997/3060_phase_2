#ifndef standarduser_h_
#define standarduser_h_

#include "user.h"
#include <iostream>
#include <string>

using namespace std;

class StandardUser: public User {
    private:
        string accountName;
    public:
        StandardUser();
        void setAccountName(string newName);
        string getAccountName();
    protected:
};

#endif
