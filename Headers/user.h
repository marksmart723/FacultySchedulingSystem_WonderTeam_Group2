#ifndef USER_H
#define USER_H

#include <string>
#include "Role.h"


class User {
private:

    bool loggedIn;
    std::string username;
    std::string password;
    Role role;

public:

    User();
    bool addUser(const std::string& uname, const std::string& pwd, const std::string& rl);
    bool login(const std::string& uname, const std::string& pwd);
    std::string getUsername();
    void changeRole(std::string& rl);
    bool isLoggedIn();
};

#endif