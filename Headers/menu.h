#pragma once

#include <user.h>
#include <string>
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
