/*
* A pay bill class which subtracts the neccessary amount from balance to pay a selected choice of companies
*/

#ifndef paybill_h_
#define paybill_h_

#include <iostream>
#include <string>
#include <regex>

#include "../user/user.h"
#include "../user/adminUser.h"
#include "../user/standardUser.h"
#include "../transaction/transaction.h"

using namespace std;

class PayBill: public Transaction{
    // Methods
    private:
	//Checks the inputted values for the company for correct that matches one of the companies available
        bool isValidCompany(string company);
	//Checks the inputted values for amount for correct formatting necessary for actions in the paybill class
        bool isValidAmount(string amount, User& user, Account& account);
    public:
	//Start of  the transaction logic where the inputs are prompted for to the user 
	//and the paybill function is fired depending on correct inputs
        bool startTransaction(AdminUser& user);
	//Start of  the transaction logic where the inputs are prompted for to the user
	// and the paybill function is fired depending on correct inputs
        bool startTransaction(StandardUser& user);
	//Mutator function subtracting the balance passed in the parameters to pay a bill 
	//from the specified account to a specified company
        void payBill(float amount, Account& account); // TODO: This should be changed to private
};

#endif
