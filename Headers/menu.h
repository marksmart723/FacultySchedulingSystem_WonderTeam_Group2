#pragma once

#include <string>
#include <user.h>
#include <iostream>
class Menu
{
private:
    bool loggedIn; 
    User currentUser; 

public:
    Menu();

    void promptLogin();

    void promptMenuInteraction();

    void displayAvailableActions(std::string role); //to do, awaiting role class

    void logout();

    void displayMenu();
};