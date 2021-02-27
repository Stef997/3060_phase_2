/*
* A an atomic login transaction which creates the bank session user and connects the user with the accounts
*/

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
	//Comparison function meant to compare two strings independent of case
        static bool noCaseComp(unsigned char a, unsigned char b);
	//Logs the user in as admin
        bool isAdmin(string session);
    public:
        string userVals[2];
	//Constructor that initializes the Login object
        Login();
	//This method overrides the startTransaction method, that takes in a user object and starts the 
	//login transaction. Logs user in as standard
        bool startTransaction(User user);
	//Creates the new session user with the required input variables inputted from the user
        string* login();

};

#endif
