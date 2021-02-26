/*
 *
 *
 */

#include "standardUser.h"

StandardUser::StandardUser() : User() {
    
}

string StandardUser::getHoldersName() {
    return holdersName;
}

void StandardUser::setHoldersName(string newName) {
    holdersName = newName;
}
