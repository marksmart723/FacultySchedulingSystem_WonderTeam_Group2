#include "../Headers/user.h"
#include <iostream>
#include <fstream>

const std::string filename = "UserInfos.txt";

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
    role = rl;
    username = uname;
    password = pwd;
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
            role = storedRole;
            username = uname;
            password = pwd;
            return true;
            file.close();
        }
    }
    std::cout << "Invalid username or password.\n";
    return false;
    file.close();
}

std::string User::getRole() {
    return role;
}

std::string User::getUsername() {
    return username;
}

std::string User::getPassword() {
    return password;
}

void User::changeRole(std::string& rl) {
    role = rl;
}

// bool User::isLoggedIn() {
    

// }