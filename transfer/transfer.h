/*
* A class that inherits the transaction class and performs an atomic operation to transfer funds to a new/separate account
*/

#ifndef transfer_h_
#define transfer_h_

#include <iostream>
#include <string>
#include <regex>

#include "../user/user.h"
#include "../user/adminUser.h"
#include "../user/standardUser.h"
#include "../transaction/transaction.h"

using namespace std;

/*
 * This class inherits transaction and is responsible 
 * of transfering money from a bank account to another bank account
 */

class Transfer: public Transaction{
    // Methods
    private:
	//Checks the input for correct formatting necessary for actions in the withdrawal class
        bool isValidAmount(string amount, User& user, Account& account1, Account& account2);
    public:
	//Mutator function modifying the account fields of a second account’s balance with passed 
	//in account and subtracting the amount from the account balance
        void transfer(float amount, Account& account1, Account& account2);
	//Start of  the transaction logic where the inputs are prompted for to the user and the transfer 
	//function is fired depending on correct inputs
        bool startTransaction(AdminUser& user);
	//Start of  the transaction logic where the inputs are prompted for to 
	//the user and the transfer function is fired depending on correct inputs
        bool startTransaction(StandardUser& user);
};

#endif
