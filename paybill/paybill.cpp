/*
* A pay bill class which subtracts the neccessary amount from balance to pay a selected choice of companies
*/

#include "paybill.h"

bool PayBill::startTransaction(AdminUser& user){
    string name;
    string nameString;
    string bankAccountID;
    string bankAccountIDString;
    string companyName;
    string amount;
    string amountString;

    cout << "Enter Account Holder’s Name:";
    cin >> name;
    
    // User Inputs
    cout << "Enter account number to pay bill from:";
    cin >> bankAccountID;

    cout << "Enter the company to pay the bill to:";
    cin >> companyName;

    cout << "Enter amount to pay:";
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
    } else if(!isValidCompany(companyName)){

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

        // Validate User Input For PayBill
        if(!isValidAmount(amount, user, account)){
            cout << "ERROR: Value Error - Account name does not exist!" << endl;
            return false;
        } else{
            payBill(stof(amount), account);
            return true;
        }
    }

    return false;
}

bool PayBill::startTransaction(StandardUser& user){
    string name;
    string nameString;
    string bankAccountID;
    string bankAccountIDString;
    string companyName;
    string amount;
    string amountString;

    name = user.getName();
    
    // User Inputs
    cout << "Enter account number to pay bill from:";
    cin >> bankAccountID;

    cout << "Enter the company to pay the bill to:";
    cin >> companyName;

    cout << "Enter amount to pay:";
    cin >> amount;

    // Validate User Input For Account
    if (!isValidAccountNumber(bankAccountID)){
        //Output error message indicating the lack of privileges
        cout << "Error: Input Value - Account number is invalid!" << endl;
        return false;
    } else if(!isValidName(name)){
        //Output error message indicating invalid info
        cout << "Error: Input Value - Account holders name is invalid!" << endl;
        return false;
    } else if(!isValidCompany(companyName)){

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

        // Validate User Input For PayBill
        if(!isValidAmount(amount, user, account)){
            cout << "ERROR: Value Error - Account name does not exist!" << endl;
            return false;
        } else{
            payBill(stof(amount), account);
            return true;
        }
    }

    return false;
}

//TODO: method should be private
void PayBill::payBill(float amount, Account& account){
    account.removeBalance(amount);

    //PayBill backend stuff
}

// TODO: Implement a company txt file and have it read over it to compare
bool PayBill::isValidCompany(string company){
    return company.compare("EC") == 0 || company.compare("CQ") == 0 || company.compare("FI") == 0;
}

// TODO: add user parameter and current balance parameter
bool PayBill::isValidAmount(string amount, User& user, Account& account){
    if (!Transaction::isValidAmount(amount)){
        return false;
    }

    // Convert inputed amount to a float value
    float value;
    string amountWithNoDollarSign;
    if (amount.substr(0,1).compare("$") == 0){
        amountWithNoDollarSign = amount.substr(1);
    }
    else{
        amountWithNoDollarSign = amount;
    }

    // convert to float value
    value = stof(amountWithNoDollarSign);

    if (!user.isAdmin() && value >= 2000){
        return false;
    }
    
    if (value < 0){
        return false;
    }

    if (value >= 100000){
        return false;
    }
    
    if (account.getBalance() - value < 0){
        return false;
    }

    return true;
}
