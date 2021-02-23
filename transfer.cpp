#include <iostream>
#include <string>
#include <regex>

using namespace std;

class Transfer {
    public: Transfer(){

    }
    
    public: float transfer()
    {
        return 0;
    }

    public: bool startTransaction(/*User user*/){
        string name;
        int bankAccountID;
        int bankAccountID2;
        string bankAccountIDString;
        float amount;

        /* TODO: Implement user and check privilege
        if (user == admin){
            cout << "Enter Account Holder’s Name:";
            cin >> name;
        }
        else{
            name = user.getName();
        }
        */
       
       /* TODO: Add enter user id in test code
       cout << ""
       cin >> bankAccountID
       */

      /* TODO: Add enter user id the user wants to transfer to in test code
       cout << ""
       cin >> bankAccountID2
       */

       /* TODO: implement an error handler for int/float values
       cout << "Enter amount to transfer:";
       cin >> amount;
       */

       // TODO: Implement a way to add 0 preceding id proceeding 5 digits to the 2 bankaccountid

       /* TODO: Add functionality, fix validity checkers, return types, and add error messages
       if (!isValidAccountNumber(bankAccountIDString)){

       } 
       else if (!isValidAccountNumber(bankAccountIDString2)){

       }
       else if(!isValidName(name)){

       } 
       else if(!isValidAmount(amount)){
           
       } 
       else{
           transfer(amount)
       }
       */
       return false;
    }

    //TODO: change int to string in UML
    private: bool isValidAccountNumber(string accountNumber){

        // Check if number is not null
        if (accountNumber.empty()){
            return false;
        }

        // Check if number is 5 characters long
        if (accountNumber.length() != 5){
            return false;
        }

        // Check if number is all integer digits
        regex regexDigits("[0-9]+");
        if (!regex_match(accountNumber, regexDigits)){
            return false;
        }

        // TODO: Check number exist in the data base

        return true;
    }

    private: bool isValidName(string name){
        // Check if name is not null or empty string
        if (name.empty() || name.compare("") == 0){
            return false;
        }

        // Check if name is at most 20 characters long and at least 1 character long
        if (name.length() > 20){
            return false;
        }

        // Check if name does not contain digits or illegal characters
        regex regexName("[^\\t\\n\\r\\f\\v0-9\\[\\]!@#$%^&*()_+{}|\\:;\"\'<,>.?/~`]+");
        if (!regex_match(name, regexName)){
            return false;
        }

        return true;
    }

    // TODO: add user parameter and current balance parameter
    private: bool isValidAmount(float amount){
        /*if (standard && amount >= 1000){
            return false;
        }
        */
       
       if (amount < 0){
           return false;
       }
       
       /*if (amount < balance){
           return false
       }*/

       return true;
    }
};
