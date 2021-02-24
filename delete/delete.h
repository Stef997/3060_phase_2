#ifndef delete_h_
#define delete_h_

#include <iostream>
#include <string>
#include <regex>

using namespace std;

class Delete {
    // Attributes
    private:

    public:

    // Methods
    private:
        bool isValidName(string name);
        bool isValidAccountNumber(string number);
    public:
        Withdrawal();
        void delete(int account);
        bool startTransaction();
};

#endif