#include "paybill.h"

PayBill::PayBill(){

}

bool PayBill::startTransaction(User user)
{
    string name;
    string nameString;
    string bankAccountID;
    string bankAccountIDString;
    string companyName;
    string amount;
    string amountString;

    /* TODO: Implement user and check privilege
    if (user == admin){
        cout << "Enter Account Holder’s Name:";
        cin >> name;
    }
    else{
        name = user.getName();
    }
    */
    
    // User Inputs
    cout << "Enter account number to pay bill from:";
    cin >> bankAccountID;

    cout << "Enter the company to pay the bill to:";
    cin >> companyName;

    cout << "Enter amount to pay:";
    cin >> amount;

    // Validate User Input
    if (!isValidAccountNumber(bankAccountID)){

    } else if(!isValidName(name)){

    } else if(!isValidCompany(companyName)){

    } else if(!isValidAmount(amount)){
        cout << "ERROR: Value Error - Account name does not exist!" << endl;
    } else{
        payBill(stof(amount));

        // Convert transaction info to transaction string format
        bankAccountIDString = bankAccountID;
        amountString = amount;
        convertAccountIDStringFormat(bankAccountIDString);
        convertCurrencyStringFormat(amountString);
        
        return true;
    }

    return false;
}

//TODO: method should be private
void PayBill::payBill(float amount){
    //PayBill backend stuff
}

// TODO: Implement a company txt file and have it read over it to compare
bool PayBill::isValidCompany(string company){
    return company.compare("EC") == 0 || company.compare("CQ") == 0 || company.compare("FI") == 0;
}

// TODO: add user parameter and current balance parameter
bool PayBill::isValidAmount(string amount){
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