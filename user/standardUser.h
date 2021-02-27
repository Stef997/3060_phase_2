/*
* An implementation of user that is lacking admin privleges and has the name set as a field
*/


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
	//Constructor that takes in a string of the account owner’s name and 
	//initializes the StandardUser object to default values
        StandardUser();
	//Constructor that takes in a string of the account owner’s name and 
	//initializes the StandardUser object to parameter values
        StandardUser(string initName);
	//Mutator method that modifies the account owner’s name
        void setName(string newName);
	//Accessor method that returns the account owner’s name
        string getName();
    protected:
};

#endif
