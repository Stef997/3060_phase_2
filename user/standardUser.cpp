/*
 *
 *
 */

#include "standardUser.h"

StandardUser::StandardUser() : User() {
    
}

string StandardUser::getName() {
    return name;
}

void StandardUser::setName(string newName) {
    name = newName;
}
