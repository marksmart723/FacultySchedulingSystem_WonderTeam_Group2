#include "../Headers/menu.h"

Menu::Menu() {}

void Menu::promptLogin()
{
    std::string username;
    std::string password;
    if(currentUser.isLoggedIn()) // Edge case if somebody call the function in code while already logged in. 
    {
        std::cout << "Error, you have already logged in.\n\n";
        return;
    }
    std::cout << "Weclome to the Faculty Scheduling System!" << "\n\n";
    std::cout << "Please enter your username: ";
    std::cin >> username;
    std::cout << "Please enter your password: ";
    std::cin >> password;

    if(currentUser.login(username, password))
        std::cout << "\n\nYou have logged in as: " << username << "\n\n";
    else 
        std::cout << "Login unsuccessful.\n\n";
    return;
}

bool Menu::promptMenuInteraction()
{
    int actionNum;
    std::cout << "Please select an option by entering the corresponding number:\n\n";
    std::cout << "1. Display my available actions\n";
    std::cout << "2. Log out\n\n";
    std::cout << "Enter your selection: ";
    std::cin >> actionNum;

    switch (actionNum) {
            case 1:
                // displayAvailableActions(role);
                break;
            case 2:
                logout();
                break;
            default:
                std::cout << "Invalid selection. Please try again.\n\n";
                return false;
        }
    return true;
}

void Menu::displayAvailableActions(std::string role)
{
    
} //to do, awaiting role class

void Menu::logout()
{
    std::cout << "User <" << currentUser.getUserName() << "> have logged out.\n\n";
    currentUser = User(); //reinitialize currentUser class member. 
    displayMenu();
}

void Menu::displayMenu()
{
    while(!currentUser.isLoggedIn())
        promptLogin();
    while(!promptMenuInteraction());
}
