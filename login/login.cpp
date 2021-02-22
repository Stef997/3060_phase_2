#include "login.h"

bool Login::isValidName(string name) {
   bool isValid = false;
   regex regexp("[a-zA-Z-]+");

   if(name.length() < 20 && name.length() > 0) {
       isValid = true;
   } else {
       isValid = false;
   }
   
   if(regex_match(name, regexp)){
       isValid = true;
   } else {
       isValid = false;
   }

   return isValid;
}

bool Login::noCaseComp(unsigned char a, unsigned char b) {
    return tolower(a) == tolower(b);
}

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

string Login::startTransaction() {
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
            return username;
        }
    } else {
        return "admin";
    }
   
    return "none";
}

void Login::login(string sessionType) {
    //Create/Retrieve user from inputted variable in startTransaction
    //Return the user/assign the BankSession's current user 
}
