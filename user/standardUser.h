#ifndef standarduser_h_
#define standarduser_h_

#include "user.h"
#include <iostream>
#include <string>

using namespace std;

class StandardUser: public User {
    private:
        string name;
    public:
        StandardUser();
        StandardUser(string initName);
        void setName(string newName);
        string getName();
    protected:
};

#endif
