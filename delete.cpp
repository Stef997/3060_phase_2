#include <iostream>
#include <string>

using namespace std;

class Delete{
    public: Delete(){

    }

    public: void deleteAccount()
    {

    }

    private: void hasDeleteAccess(User user)
    {
        //check whether or not the user is permitted to perform the transaction
        if (!user) {
            return false;
        }

        if (user->user_type == "User") return true;
        return false;
    }

    private: void isValidAccountNumber(string accountNumber) //Check if account number is valid 
    {
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

    private: void isValidName(string name)
    {
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

    private: void startTransaction(){
        string name;
        string newName;
        int bankAccountID;
        string bankAccountIDString;
        float amount;

        cout << "Enter Account Holder's Name";
        cin >> name;

        cout << "Enter The Account Number";
        cin >> bankAccountID
    }


}