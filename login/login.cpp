/*
* A an atomic login transaction which creates the bank session user and connects the user with the accounts
*/

#include "login.h"

//Constructor that initializes the Login object
Login::Login() : Transaction() {

}

//Comparison function meant to compare two strings independent of case
bool Login::noCaseComp(unsigned char a, unsigned char b) {
    return tolower(a) == tolower(b);
}

//Logs the user in as admin
bool Login::isAdmin(string session) {
     bool isAdmin = false;

     string adminStr = "admin";
     string standardStr = "standard";

     if(session.length() == adminStr.length()){
        isAdmin = equal(session.begin(), session.end(),
                        adminStr.begin(), noCaseComp);
        if(isAdmin) {
           return true;
        } else {
            cout << "Error: Invalid session type" << endl;
        } 
     } else if(session.length() == standardStr.length()) {
        bool isStandard = equal(session.begin(), session.end(),
                        standardStr.begin(), noCaseComp);
        if(isStandard) {
            isAdmin = false;
        } else {
            cout << "Error: Invalid session type!" << endl;
        }
     } else {
        cout << "Error: Invalid session type!" << endl;
     }

  return isAdmin;
}

//This method overrides the startTransaction method, that takes in a user object and starts 
//the login transaction. Logs user in as standard
bool Login::startTransaction(User user) {
	return true;
}

//Creates the new session user with the required input variables inputted from the user
string* Login::login() {

    string username;
    string sessionType;

    cout << "Hello, please Enter Session Type: ";
    cin >> sessionType;
    
    bool isAdminUser = isAdmin(sessionType);
       
    if(isAdminUser == false) {
        cout << "Please enter account holder's name: ";
        cin >> username;
        bool isValid = isValidName(username);
        if(isValid) {
            userVals[0] = sessionType;
            userVals[1] = username;
            return userVals;
        }
    } else {
        userVals[0] = sessionType;
        userVals[1] = "";
        return userVals;
    }
   
    return userVals;
}
