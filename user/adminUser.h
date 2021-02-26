#ifndef adminuser_h_
#define adminuser_h_

#include "user.h"
#include <iostream>
#include <string>

using namespace std;

class AdminUser: public User {
    private:
        bool status = false;
    public:
        AdminUser();
        void setAdmin();
        bool isAdmin();
    protected:  
};

#endif
