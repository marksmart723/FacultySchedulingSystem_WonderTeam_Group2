#include "menu.h"

#include <windows.h>
#include <cstdlib>

Menu::Menu(): permissions() {}

void clearConsole()
{
    Sleep(700);
    std::system("cls");
}

void cinClear()
{
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}

void Menu::promptLogin() {
    clearConsole();

    std::string username;
    std::string password;

    std::cout << "RBAC: Welcome to the Faculty Scheduling System!" << "\n\n";
    std::cout << "Please enter your username: ";
    std::cin >> username;
    std::cout << "Please enter your password: ";
    std::cin >> password;
    std::cout << std::endl;
    if (currentUser.login(username, password)) {
        std::cout << "RBAC: You have logged in as user <" << username << ">";
        permissions = currentUser.getRole().getPermissions();
    } else
        std::cout << "RBAC: Login unsuccessful.";
    std::cout << "\n\n";
}

int Menu::promptMenuInteraction()
{
    int actionNum;
    while (true)
    {
        clearConsole();
        std::cout << "RBAC: Please select an option by entering the corresponding number:\n\n";
        std::cout << "1. Display my available actions\n";
        std::cout << "2. Log out\n\n";
        std::cout << "Enter your selection: ";
        std::cin >> actionNum;

        if (std::cin.fail() || actionNum < 1 || actionNum > 2)
        {
            cinClear();
            std::cout << "\nInvalid input or selection. Please try again.";
            continue;
        }
        return actionNum;
    }
}

int Menu::promptActionSelection()
{
    int actionNum;
    while (true) {
        clearConsole();
        std::cout << "User <" << currentUser.getUsername() << "> Available actions:\n\n";
        for (size_t i = 0; i < permissions.size(); ++i) {
            std::cout << i + 1 << ". " << permissions[i] << "\n";
        }
        std::cout << "\nSelect an action by entering its number: ";
        std::cin >> actionNum;

        if (std::cin.fail() || actionNum < 1 || actionNum > permissions.size()) {
            cinClear();
            std::cout << "\nInvalid selection. Please try again.";
            clearConsole();
            continue;
        }
        return actionNum;
    }
}

void Menu::executeAction(int num) {
    clearConsole();
    std::cout << "Executing action: " << permissions[num-1];
}

void Menu::logout() {
    clearConsole();
    std::cout << "User <" << currentUser.getUsername() << "> have logged out.";
    currentUser = User(); //reinitialize currentUser class member.
    displayMenu();
}

void Menu::displayMenu()
{
    while (!currentUser.isLoggedIn())
        promptLogin();
    while (true) {
        int menuChoice = promptMenuInteraction();
        if (menuChoice == 2) {  //User wants to log out
            logout();
            return;
        }
        if (menuChoice == 1) {
            int action = -1;
            while (action < 1) { //Ensure valid action
                action = promptActionSelection();
            }
            executeAction(action);
        }
    }
}
