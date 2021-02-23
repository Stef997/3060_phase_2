#ifndef account_h_
#define account_h_

#include <iostream>
#include <string>

using namespace std;

class Account { 
    private:
        string number;
        float balance;
        string plan;
    public:
        Account();
        string getNumber();
        void setNumber(string newNumber);
        float getBalance();
        void addBalance(float newBalance);
        string getPlan();
        void setPlan(string newPlan);
    protected:
};

#endif
