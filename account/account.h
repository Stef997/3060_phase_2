#ifndef account_h_
#define account_h_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account { 
    private:
        string number;
        string name;
        string status;
        float balance;
        string plan;
    public:
        Account();
        Account(string bankAccountLine);
        string getName();
        string getNumber();
        void setNumber(string newNumber);
        string getPlan();
        void setPlan(string newPlan);
        float getBalance();
        void addBalance(float newBalance);
        void removeBalance(float newBalance);
    protected:
};

#endif
