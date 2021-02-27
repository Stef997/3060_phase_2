/*
 * A C++ implementation of a admin user based from a user
 * class to operate with full privileges in a ATM banking 
 * session
 */

#include "adminUser.h"
#include "../account/account.h"

//Constructor that initializes the AdminUser object
AdminUser::AdminUser() : User(){

}

//Returns whether admin field has been successfully set
void AdminUser::setAdmin(){
   status = true;
}

//Mutator method which swaps the values of the status field
bool AdminUser::isAdmin(){
    return status;
}

