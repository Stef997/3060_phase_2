/*
 * A C++ implementation of a admin user based from a user
 * class to operate with full privileges in a ATM banking 
 * session
 */

#ifndef user_h_
#define user_h_

#include <iostream>
#include <string>
#include "../account/account.h"

using namespace std;

class User: public Account {
    private:
        /*Account* bankAccounts;*/
        vector<Account> bankAccounts;

    public:
	//Accessor method that returns a list of Account objects the user owns
        vector<Account> getBankAccounts();
	//Mutator method that adds the new account to a list of Account objects the user owns
        void addAccount(Account account);
        /*void setBankAccounts(Account* accounts);*/
	//Returns whether the admin field has been set
        bool isAdmin();
	//Returns whether the account belongs to the specific user by comparing the user fields with parameters
        bool findAccount(string name, string id);
	//Instantiate an account based on the parameter values
        void createAccount(string name, float amount);
	//Delete the account specified by parameter values
        void deleteAccount(string name, string id);
	//Return the account by reference of the requested account with the same ID belonging to the user
        Account& getAccount(string name, string id);
};

#endif
