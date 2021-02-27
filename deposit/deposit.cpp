/*
 * Deposit transaction class. Takes the address of a user
 * and adds a value to the account class associated with
 * the user using the named 'deposit' class with
 * supplementary functions intended to check for correct
 * inputs.
 *
 */

#include "deposit.h"

/*
 * This method takes an admin user object. It then prompts the 
 * user for input, tests the input, and deposits the money into 
 * the bank account if all inputs are valid.
 */
bool Deposit::startTransaction(AdminUser& user) {
    string name;
    string nameString;
    string bankAccountID;
    string bankAccountIDString;
    string amount;
    string amountString;

    if (user.isAdmin()){
        cout << "Enter Account Holder’s Name:";
        cin >> name;
    }
    else{
        name = user.getName();
    }

    // User Input
    cout << "Enter account number to deposit to:";
    cin >> bankAccountID;

    cout << "Enter amount to deposit:";
    cin >> amount;

    
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
        bankAccountIDString = bankAccountID;
        amountString = amount;
        nameString = name;
        convertNameStringFormat(nameString);
        convertAccountIDStringFormat(bankAccountIDString);
        convertCurrencyStringFormat(amountString);

        // Find User
        if (!user.findAccount(name, bankAccountID)){
            return false;
        }
        // Get user account
        Account& account = user.getAccount(name, bankAccountID);

        // Validate User Input For Deposit
        if(!isValidAmount(amount, account)){
            cout << "Error: invalid value amount!" << endl;
            return false;
        } else{
            // Deposit into user account
            deposit(stof(amountString), account);
            return true;
        }
    }
    
    return false;
}

/*
 * This method takes a standard user object. It then prints an error 
 * message for invalid privilege and returns false.
 */
bool Deposit::startTransaction(StandardUser& user) {
    string name;
    string nameString;
    string bankAccountID;
    string bankAccountIDString;
    string amount;
    string amountString;

    if (user.isAdmin()){
        cout << "Enter Account Holder’s Name:";
        cin >> name;
    }
    else{
        name = user.getName();
    }

    // User Input
    cout << "Enter account number to pay bill from:";
    cin >> bankAccountID;

    cout << "Enter amount to deposit:";
    cin >> amount;

    
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
        bankAccountIDString = bankAccountID;
        amountString = amount;
        nameString = name;
        convertNameStringFormat(nameString);
        convertAccountIDStringFormat(bankAccountIDString);
        convertCurrencyStringFormat(amountString);

        // Find User
        if (!user.findAccount(name, bankAccountID)){
            return false;
        }
        // Get user account
        Account& account = user.getAccount(name, bankAccountID);

        // Validate User Input For Deposit
        if(!isValidAmount(amount, account)){
            cout << "Error: invalid value amount!" << endl;
            return false;
        } else{
            // Deposit into user account
            deposit(stof(amountString), account);
            return true;
        }
    }
    
    return false;
}

/*
 * This method takes in a float values and Account object. 
 * It then adds the float value to the balance of the account.
 */
//Apply changes to the account associated with the user
void Deposit::deposit(float amount, Account& account){
    account.addBalance(amount);

    // TODO: back end stuff
}

/*
 * This method takes in a string and account and checks if the string
 * follows the requirements of deposit and does not go under or over 
 * the boundaries of the account balance.
*/
// TODO: add user parameter and current balance parameter
bool Deposit::isValidAmount(string amount, Account account){

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
    if (value + account.getBalance() >= 10000){
        return false;
    }

    return true;
}
