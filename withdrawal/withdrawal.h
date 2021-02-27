/*
* An atomic transaction for withdrawal which subtracts from the available user accounts
*/

#ifndef withdrawal_h_
#define withdrawal_h_

#include <iostream>
#include <string>
#include <regex>

#include "../user/user.h"
#include "../user/adminUser.h"
#include "../user/standardUser.h"
#include "../transaction/transaction.h"

using namespace std;

class Withdrawal: public Transaction{
    // Methods
    private:
	//Checks the input for correct formatting necessary for actions in the withdrawal class
        bool isValidAmount(string amount, User& user, Account& account);
    public:
	//Mutator function modifying the account fields of the passed in account and 
	//subtracting the amount from the account balance
        void withdraw(float amount, Account& account);
	//Start of  the transaction logic where the inputs are prompted for to the user 
	//and the withdraw function is fired depending on correct inputs
        bool startTransaction(AdminUser& user);
	//Start of  the transaction logic where the inputs are prompted for
	//to the user and the withdraw function is fired depending on correct inputs
        bool startTransaction(StandardUser& user);
};

#endif
