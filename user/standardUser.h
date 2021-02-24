#ifndef standarduser_h_
#define standarduser_h_

#include "user.h"
#include <iostream>
#include <string>

using namespace std;

class StandardUser: public User {
    private:
        string holdersName;
    public:
        void setHoldersName(string newName);
        string getHoldersName();
        bool isAdmin();
    protected:
};

#endif
