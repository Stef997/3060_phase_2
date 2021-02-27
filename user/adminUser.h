/*
* An implementation of user with a status flag indicating the user has privileges to all transactions
*/

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
	//Constructor that initializes the AdminUser object
        AdminUser();
	//Mutator method which swaps the values of the status field
        void setAdmin();
	//Returns whether admin field has been successfully set
        bool isAdmin();
    protected:  
};

#endif
