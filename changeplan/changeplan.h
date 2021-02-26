#include <iostream>
#include <string>
#include "../user/user.h"
#include "../user/adminUser.h"
#include "../user/standardUser.h"
#include "../transaction/transaction.h"
#include <string>

using namespace std;

class ChangePlan: public Transaction {
    private:
        StandardUser user;
        string accountName;
    public:
        StandardUser getUser();
        bool startTransaction(User user);
}; 
