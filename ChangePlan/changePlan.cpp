#include "changePlan.h"

ChangePlan::ChangePlan(){

}

void ChangePlan::setPlan(Account& account){
    account.changePlan();
}

bool ChangePlan::startTransaction(User user){
    string name;
    string nameString;
    string bankAccountID;
    string bankAccountIDString;
    Account account;

    // Check If User Is Admin Session Before Proceeding
    if (!user.isAdmin()){
        cout << "ERROR: Transaction Error: Cannot access the change plan transaction" << endl;
        return false;
    }

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
        if (!user.findAccount(nameString, bankAccountIDString)){
            return false;
        }

        // Get user account
        account = user.getAccount(nameString, bankAccountIDString);

        // Change Account Plan
        setPlan(account);
    }
}