#pragma once

#include "user.h"
#include <string>
#include <iostream>

class Menu
{
private:
    User currentUser;
    std::vector<std::string> permissions;

public:
    Menu();
    void promptLogin();
    int promptMenuInteraction();
    int promptActionSelection();
    void executeAction(int num);
    void logout();
    void displayMenu();
};
