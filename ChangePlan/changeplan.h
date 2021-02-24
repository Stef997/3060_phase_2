#include <iostream>
#include <string>
#include "../user/user.h"
#include "../user/adminUser.h"
#include "../user/standardUser.h"
#include <string>
using namespace std;

class ChangePlan {
   private:
        StandardUser user;
        string accountName;
    public:
    StandardUser getUser();
    bool startTransaction(User user);
    bool isValidName(string name);
    bool isValidAccountNumber(string number, Account* accounts);
    string getPlan();
    void setPlan(string newPlan);
}; 