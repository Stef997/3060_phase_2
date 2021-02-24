#include <iostream>
#include <string>
#include "../user/user.h"
#include "../user/adminUser.h"
#include "../user/standardUser.h"
#include <string>
using namespace std;

class Disabke {
   private:
    public:
    string getTransactionName();
    StandardUser getUser();
     bool startTransaction(User user);
    bool isValidName(string name);
    bool isValidAccountNumber(string number, Account* accounts);
};