#include "user.h"
#include <iostream>
#include <fstream>

const std::string filename = "UserInfos.txt";

User::User() {
    loggedIn = false;
}

bool User::addUser(const std::string& uname, const std::string& pwd, const std::string& rl) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file for writing.\n";
        return false;
    }
    std::string storedUname;
    while (file >> storedUname) {
        if (uname == storedUname) {
            std::cout << "Username Taken." << "\n";
            file.close();
            return false;
        }
    }
    file.close();
    std::ofstream file1(filename, std::ios::app);
    file1 << uname << " " << pwd << " " << rl << "\n";
    role = Role(rl);
    username = uname;
    password = pwd;
    loggedIn = true;
    file1.close();
    std::cout << "User added successfully.\n";
    return true;
}
bool User::login(const std::string& uname, const std::string& pwd) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file for reading.\n";
        return false;
    }

    std::string storedUname, storedPwd, storedRole;
    while (file >> storedUname >> storedPwd >> storedRole) {
        if (uname == storedUname && pwd == storedPwd) {
            std::cout << "Login successful." << "\n";
            role = Role(storedRole);
            username = uname;
            password = pwd;
            loggedIn = true;
            file.close();
            return true;
        }
    }
    std::cout << "Invalid username or password.\n";

    file.close();
    return false;
}

std::string User::getUsername() {
    return username;
}

void User::changeRole(std::string& rl) {
    role = Role(rl);
}

bool User::isLoggedIn() {
    return loggedIn;
}

std::string User::getRolename() const {
    return role.getRole();
}

const Role& User::getRole() const {
    return role;
}
