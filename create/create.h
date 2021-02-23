#ifndef create_h_
#define create_h_

#include <iostream>
#include <string>
#include <regex>

using namespace std;

class Create {
    // Attributes
    private:

    public:

    // Methods
    private:
        bool isValidName(string name);
        bool isValidAmount(string amount);
    public:
        Create();
        void create(float amount);
        bool startTransaction();
};

#endif