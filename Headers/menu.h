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
    void displayAvailableActions();
    void logout();
    void displayMenu();
};
