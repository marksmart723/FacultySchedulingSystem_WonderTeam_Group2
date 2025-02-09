#include "menu.h"

#include <windows.h>
#include <cstdlib>

Menu::Menu(): permissions() {}

void displayRBACHeader()
{
    std::cout << "==========================================\n";
    std::cout << "                  ~RBAC~    \n";
    std::cout << "==========================================\n\n";
}

void clearConsole()
{
    Sleep(400);
    std::system("cls");
}

void cinClear()
{
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}

void Menu::promptLogin() {
    clearConsole();
    displayRBACHeader();

    std::string username;
    std::string password;

    std::cout << "Welcome to the Faculty Scheduling System!" << "\n\n";
    std::cout << "Please enter your username: ";
    std::cin >> username;
    std::cout << "Please enter your password: ";
    std::cin >> password;
    std::cout << std::endl;
    if (currentUser.login(username, password)) {
        std::cout << "You have logged in as user <" << username << ">";
        permissions = currentUser.getRole().getPermissions();
    } else
        std::cout << "Login unsuccessful.";
}

int Menu::promptMenuInteraction()
{
    int actionNum;
    while (true)
    {
        clearConsole();
        displayRBACHeader();
        std::cout << "Please select an option by entering the corresponding number:\n\n";
        std::cout << "1. Display my available actions\n";
        std::cout << "2. Log out\n";

        std::cout << "\n0. Exit the program\n";
        std::cout << "\nSelection an option by entering its number: ";
        std::cin >> actionNum;

        if (std::cin.fail() || actionNum < 0 || actionNum > 2)
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
        displayRBACHeader();
        std::cout << "User <" << currentUser.getUsername() << "> Available actions:\n\n";
        for (int i = 0; i < permissions.size(); i++) { //get all available actions. May change in the future.
            std::cout << i + 1 << ". " << permissions[i] << "\n";
        }

        std::cout << "\n0. Go back to previous page\n";
        std::cout << "\nSelect an action by entering its number: ";
        std::cin >> actionNum;

        if (std::cin.fail() || actionNum < 0 || actionNum > permissions.size()) {
            cinClear();
            std::cout << "\nInvalid selection. Please try again.";
            continue;
        }
        return actionNum;
    }
}

void Menu::executeAction(int num) const
{
    clearConsole();
    displayRBACHeader();
    std::cout << "Executing action: " << permissions[num-1];
}

void Menu::logout() {
    clearConsole();
    displayRBACHeader();
    std::cout << "User <" << currentUser.getUsername() << "> have logged out.";
    currentUser = User(); //reinitialize currentUser class member.
    permissions.clear();
}

void Menu::displayMenu()
{
    bool running = true;
    while (running) //main event loop
    {
        if (!currentUser.isLoggedIn())
            promptLogin();
        while (currentUser.isLoggedIn() && running) {
            int menuChoice = promptMenuInteraction();
            if (menuChoice == 0)
                running = false;//User want to exit program
            else if (menuChoice == 2) {  //User wants to log out
                logout();
            }
            else if (menuChoice == 1) {
                int action = -1;
                while (action < 0) { //Ensure valid action
                    action = promptActionSelection();
                    if (action >= 1)
                    {
                        executeAction(action); //execute the action.
                        action = -1; //reset the action value for the next loop.
                    }
                    if (action == 0) //break loop that ask for action selection
                        break;
                }

            }
        }
    }
}
