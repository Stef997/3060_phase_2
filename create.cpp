#include <iostream>
#include <string>

using namespace std;

class Create {
    public: Create(){

    }

    public: void createAccount()
    {

    }

    private: void hasCreateAccess(User user)
    {
        //check whether or not the user is permitted to perform the transaction
        if (!user) {
            return false;
        }

        if (user->user_type == "admin") return true;
        return false;
    }

    private: void startTransaction(User user)
    {
        string name;
        string newName;
        int bankAccountID;
        string bankAccountIDString;
        float amount; 

        if (user == 'admin'){
            cout << "Enter Account Holder's Name:";
            cin >> name;
        }

        cout << "Enter New Account's Name:"
        cin>> newName;

        cout << "Enter Initial Balance";
        cin >> balance;
    }

    private: void isValidName(String name)
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

    private: void isValidAmount(float amount)
    {
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