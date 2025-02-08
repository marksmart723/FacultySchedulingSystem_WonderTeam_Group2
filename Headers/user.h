#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string username;
    std::string password;
    std::string role;

public:
    bool addUser(const std::string& uname, const std::string& pwd, const std::string& rl);
    bool login(const std::string& uname, const std::string& pwd);
    std::string getRole();
    std::string getUsername();
    std::string getPassword();
    void changeRole(std::string& rl);
    bool isLoggedIn();
};

#endif

