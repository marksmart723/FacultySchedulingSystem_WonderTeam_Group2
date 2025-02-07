#pragma once

#include <string>
#include <user.h>
#include <iostream>
class Menu
{
private:
    User currentUser; 

public:
    Menu();

    void promptLogin();

    bool promptMenuInteraction();

    void displayAvailableActions(std::string role); //to do, awaiting role class

    void logout();

    void displayMenu();
};
