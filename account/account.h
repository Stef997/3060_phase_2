#ifndef account_h_
#define account_h_

#include <iostream>
#include <string>

using namespace std;

class Account { 
    private:
        int number = 0;
        float balance = 0;
        string plan;
    public:
        int getNumber();
        float getBalance();
        string getPlan();
        void setPlan(string newPlan);
    protected:
};

#endif
