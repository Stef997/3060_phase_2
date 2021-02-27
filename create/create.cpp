#include "create.h"


/*
 * his method takes a standard user object. It then prints an error 
 * message for invalid privilege and returns false.
 */
bool Create::startTransaction(StandardUser& user){
    cout << "ERROR: Transaction Error - Delete transaction cannot be accessed from a standard account" << endl;
    return false;
}

/*
 * This method takes an admin user object. It then prompts the user for input, 
 * tests the input, and creates a new bank account if all inputs are valid.
 */
bool Create::startTransaction(AdminUser& user){
    string name;
    string nameString;
    string amount;
    string amountString;
    Account account;

    // User Input
    cout << "Enter Account Holder’s Name:";
    cin >> name;

    cout << "Enter Initial Balance:";
    cin >> amount;

     // Validate User Input For Account
    if(!isValidName(name)){
        //Output error message indicating invalid info
        cout << "Error: Account holders name is invalid!" << endl;
        return false;
    } else{
        // Convert transaction info to transaction string format
        nameString = name;
        convertNameStringFormat(nameString);
    }

    // Validate User Input For Create Account
    if(!isValidAmount(amount)){
        cout << "Error: invalid value amount!" << endl;
        return false;
    } else{
        // Create Account
        createAccount(user, name, stof(amountString));
    }
}

/*
 * This method takes in an admin user, the name of the account as a string, 
 * and the initial balance as a float value. It then creates a bank account.
 */
void Create::createAccount(AdminUser& user, string name, float amount){
    user.createAccount(name, amount);
}

/*
 * This method takes in a string and checks if the string follows the requirements
 * of the initial balance and does not go under or over the boundaries of the account balance.
 */
bool Create::isValidAmount(string amount){
    if (!Transaction::isValidAmount(amount)){
        return false;
    }

    // Convert inputted amount to a float value
    float value;
    string amountWithNoDollarSign;

    //Check for dollar sign within amount string
    if (amount.substr(0,1).compare("$") == 0){
        amountWithNoDollarSign = amount.substr(1);
    }
    else{
        amountWithNoDollarSign = amount;
    }

    // convert to float value
    value = stof(amountWithNoDollarSign);
    
    //Check for negative values
    if (value < 0){
        return false;
    }
    
    //Check for the value amount on deposits
    if (value >= 100000){
        return false;
    }

    return true;
}