#include "disable.h"

bool Disable::startTransaction(StandardUser& user){
    cout << "ERROR: Transaction Error - Cannot access disable transaction from standard account!" << endl;
    return false;
}

bool Disable::startTransaction(AdminUser& user) {
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

        // Get user account
        Account& account = user.getAccount(name, bankAccountIDString);

        // Change Account Plan
        disableAccount(account);
    }
}

void Disable::disableAccount(Account& account){
    account.disable();
}