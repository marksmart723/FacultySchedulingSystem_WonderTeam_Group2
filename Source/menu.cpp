#include "../Headers/menu.h"

Menu::Menu() {}

void Menu::promptLogin()
{
    std::string username;
    std::string password;
    if(currentUser.isLoggedIn())
    {
        std::cout << "Error, you have already logged in." << std::endl;
        return;
    }
    std::cout << "Weclome to the Faculty Scheduling System!" << "\n\n";
    std::cout << "Please enter your username: ";
    std::cin >> username;
    std::cout << std::endl;
    std::cout << "Please enter your password: ";
    std::cin >> password;

    if (currentUser.login(username, password))
    {
        std::cout << "You have logged in as: " << username << std::endl;
        std::cout << "Your Role: " << currentUser.getRoleName() << std::endl;
    }
    return;
}

void Menu::promptMenuInteraction()
{
    int actionNum;
    std::cout << "Please select an option by entering the corresponding number: \n";
    std::cout << "1. Display my available actions" << "2. Log out.";
    std::cout << "Enter your selection: ";
    std::cin >> actionNum;

    switch (actionNum) {
            case 1:
                // displayAvailableActions(role);
                std::cout << "\n\n\n";  
                break;
            case 2:
                logout();
                std::cout << "\n\n\n";  
                break;
            default:
                std::cout << "Invalid selection. Please try again." << std::endl;
        }
}

void Menu::displayAvailableActions(std::string role)
{
    
} //to do, awaiting role class

void Menu::logout()
{
    currentUser = User();
    promptLogin();
}

void Menu::displayMenu()
{
    while(!currentUser.isLoggedIn())
        promptLogin();
}