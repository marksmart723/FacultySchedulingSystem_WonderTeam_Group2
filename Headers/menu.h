#pragma once

#include "user.h"
#include <string>
#include <iostream>

class Menu
{
private:
    User currentUser;
    std::vector<std::string> permissions; //Holds the currentUser permissions.
    //Maybe in the future there will be a map or vector to store pointers to functions.
    //PromptMenuInteraction will return the key to access these functions.

    void promptLogin(); //Ask user to enter their login information.
    int promptMenuInteraction(); //Ask user which menu choice they want. Return the choice.
    int promptActionSelection(); //Ask user which action choice they want. Return the choice.
    void executeAction(int num) const; //Use the returned value from promptActionSelection. Execute the permissions.
    void logout(); //Reinitialize the currentUser private member.

public:
    Menu();

    void displayMenu(); //Start the main Menu loop
};
