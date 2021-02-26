#include <iostream>
#include <string>
#include <regex>

using namespace std;

class Login {
    private: bool isValidName(string name) {
       bool isValid = true;
       regex regexp("[a-zA-Z-]+");

       if(name.length() < 20 && name.length() > 0) {
           isValid = true;
       } 
       
       if(regex_match(name, regexp)){
           isValid = true;
       } else {
           isValid = false;
       }

       return isValid;
    }
    
    private: static  bool noCaseComp(unsigned char a, unsigned char b) {
        return tolower(a) == tolower(b);
    }

    private: bool isAdmin(string session) {
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

    public: void startTransaction() {
        string username;
        string sessionType;

        cout << "Hello, " << endl;
        cout << "Please Enter Session Type: ";
        cin >> sessionType;
        
        bool isAdminUser = isAdmin(sessionType);
           
        if(isAdminUser == false) {
            cout << "Please enter account holder's name: " << endl;
            cin >> username;
            bool isValid = isValidName(username);
        } else {
            cout << "Admin logged in" << endl;
        }
    }

    public: void login(string sessionType) {
        //Create/Retrieve user from inputted variable in startTransaction
        //Return the user/assign the BankSession's current user 
    }
};
