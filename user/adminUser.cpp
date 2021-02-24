/*
 * A C++ implementation of a admin user based from a user
 * class to operate with full privileges in a ATM banking 
 * session
 */

#include "adminUser.h"
#include "../account/account.h"

AdminUser::AdminUser() : User(){

}

bool AdminUser::isAdmin(){
    return true;
}

