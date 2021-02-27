#include "withdrawal.h"

Withdrawal::Withdrawal(){

}

bool Withdrawal::startTransaction(User user)
{
    string name;
    string nameString;
    string bankAccountID;
    string bankAccountIDString;
    string amount;
    string amountString;

    /* TODO: Implement user and check privilege
    if (user == admin){
        cout << "Enter Account Holder’s Name:";
        cin >> name;
    }
    */
    
    name = user.getName();

    // TODO: Add enter user id in test code
    // User Input
    cout << "Enter account number to withdraw from:";
    cin >> bankAccountID;

    cout << "Enter amount to withdraw:";
    cin >> amount;
    
    // Validate User Input
    if (!isValidAccountNumber(bankAccountID)){
        cout << "Error: Value Error - Account number does not exist!" << endl;
    } else if(!isValidName(name)){
        cout << "Error: Input Error - Account name does not belong to user!" << endl;
        return false;
    } else if(!isValidAmount(amount)){
        cout << "Error: Value Error - Not a valid currency value!" << endl;
        return false;
    } else{
        Account& account = user.getAccount(name, bankAccountID);
        withdraw(stof(amount), account);

        // Convert transaction info to transaction string format
        bankAccountIDString = bankAccountID;
        amountString = amount;
        convertAccountIDStringFormat(bankAccountIDString);
        convertCurrencyStringFormat(amountString);
    }
    return true;
}

//TODO: method should be private
void Withdrawal::withdraw(float amount, Account& account){
    account.removeBalance(amount);
    //Withdraw backend stuff
}

// TODO: add user parameter and current balance parameter
bool Withdrawal::isValidAmount(string amount){

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

    // Check if value is within boundaries 
    /*if (standard && value >= 2000){
        return false;
    }
    */
    
    if (value < 0){
        return false;
    }
    
    /*if (value < balance){
        return false
    }*/

    return true;
}
