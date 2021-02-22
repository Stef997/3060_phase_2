#include "user/user.h"
#include "user/adminUser.h"
#include "user/standardUser.h"
#include <iostream>

using namespace std;

int main() {
    StandardUser stanUser = StandardUser();
    string username  = stanUser.getAccountName();
    stanUser.setPlan("Student");
    string currentPlan = stanUser.getPlan();
    cout << currentPlan << endl;
}
