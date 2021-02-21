/*
 * A C++ implementation of a admin user based from a user
 * class to operate with full privileges in a ATM banking 
 * session
 */

#include "adminUser.h"

AdminUser::AdminUser() {
    string* accounts = new string[1]{"none"};
    AdminUser::setBankAccounts(accounts);
}

