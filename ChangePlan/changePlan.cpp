#include <iostream>
#include <string>
#include <regex>
#include "user.h"
using namespace std;

class ChangePlan {
    public: ChangePlan(){

    }

    public: setPlan(string plan){

    }

    public: startTransaction(User user){

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

       return true;
    }
};