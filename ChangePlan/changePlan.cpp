#include "changePlan.h"

void ChangePlan::setPlan(Account& account){
    account.changePlan();
}

<<<<<<< HEAD
bool ChangePlan::startTransaction(StandardUser& user){
    cout << "ERROR: Transaction Error: Cannot access the change plan transaction" << endl;
    return false;
}

bool ChangePlan::startTransaction(AdminUser& user){
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
        cout << "Error: Input Error - Account number is invalid!" << endl;
        return false;
    } else if(!isValidName(name)){
        //Output error message indicating invalid info
        cout << "Error: Input Error - Account holders name is invalid!" << endl;
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
        setPlan(account);
    }
}

bool ChangePlan::startTransaction(StandardUser& user) {
    cout << "Error: Transaction Error - Cannot access the change plan transaction from a standard account!" << endl;
}
