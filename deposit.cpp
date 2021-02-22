#include <iostream>
#include <string>

using namespace std;

class Deposit {
    public: Deposit(){

    }

    private: startTransaction(){
        //have to add conditions for each statements
        string name;
        string newName;
        int bankAccountID;
        string bankAccountIDString;
        float amount;

        cout << "Enter Account Holder's Name";
        cin >> name;

        cout << "Enter The Account Number To Deposit To";
        cin >> bankAccountID
    }

    public: void deposit(int value){

    }

    private: void isValidAccountNumber(string accountNumber){
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

        return true;
    }

    private: void isValidName(){
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

    private: void isValidAmount(float amount){
        /*if (standard && amount >= 500){
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


}