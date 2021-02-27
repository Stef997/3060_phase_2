#include "delete.h"

bool Delete::startTransaction(StandardUser& user){
    cout << "ERROR: Transaction Error - Delete transaction cannot be accessed from a standard account" << endl;
    return false;
}

bool Delete::startTransaction(AdminUser& user){
    string name;
    string nameString;
    string bankAccountID;
    string bankAccountIDString;

    // User Input
    cout << "Enter Account Holder’s Name:";
    cin >> name;

    cout << "Enter Account Number:";
    cin >> bankAccountID;

     // Validate User Input For Account
    if (!isValidAccountNumber(bankAccountID)){
        //Output error message indicating the lack of privileges
        cout << "Error: Account number is invalid!" << endl;
        return false;
    } else if(!isValidName(name)){
        //Output error message indicating invalid info
        cout << "Error: Account holders name is invalid!" << endl;
        return false;
    } else{
        // Convert transaction info to transaction string format
        nameString = name;
        bankAccountIDString = bankAccountID;
        convertNameStringFormat(nameString);
        convertAccountIDStringFormat(bankAccountIDString);

        // Find User
        if (!user.findAccount(name, bankAccountIDString)){
            return false;
        }

        Account& account = user.getAccount(name, bankAccountIDString);

        // Delete Account
        deleteAccount(user, name, bankAccountIDString);
    }
}

void Delete::deleteAccount(AdminUser& user, string name, string id){
    user.deleteAccount(name, id);
}