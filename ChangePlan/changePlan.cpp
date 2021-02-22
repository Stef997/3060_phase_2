#include <iostream>
#include <string>
#include <regex>
#include "../user/user.h"

using namespace std;

class ChangePlan {
    public: ChangePlan(){

    }

    public: void setPlan(string plan){

    }

    public: void startTransaction(User user){
        string name;
        string newName;
        int bankAccountID;
        string bankAccountIDString;
        float amount;

        cout << "Enter Account Holder's Name";
        cin >> name;

        cout << "Enter The Account Number To Deposit To";
        cin >> bankAccountID;
    }

    
    private: bool isValidAccountNumber(string accountNumber){

     return false;
    }
        //got from stephan
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
