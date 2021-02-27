/*
* Class containing the account of a user with fields intended for modifications by the ATM system
*/

#ifndef account_h_
#define account_h_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account { 
    private:
        string number;
        string name;
        string status;
        float balance;
        string plan;
    public:
	//Instantiates the account with default values
        Account();
	//Sets the account field to match bank account files attributes
        Account(string bankAccountLine);
	//Accessor method that returns the account holders name
        string getName();
	//Mutator method taking in a new name and sets the account holder’s name to the new name
        void setName(string newName);
	//Accessor method that returns the bank account ID number
        string getNumber();
	//Mutator method accepting a string to change the accounts ID number to the new number
        void setNumber(string newNumber);
	//Accessor method that returns the payment plan of the bank account
        string getPlan();
	//Mutator method that takes in a string which changes the account’s payment plan to either 
	//student (if string value is “SP”) or non-student (if string value is “NP”)
        void changePlan();
	//Accessor method that returns the balance of the bank account
        float getBalance();
	//Mutator method which switches the disable status of the account
        void disable();
	//Mutator method which modifies the balance field of the account to reflect the new balance after adding 
	//the newBalance value to the previous balance
        void addBalance(float newBalance);
	//Mutator method which modifies the balance field of the account to reflect the new balance after 
	//adding the newBalance value to the previous balance
        void removeBalance(float newBalance);
    protected:
};

#endif
