#pragma once

#include <string>
#include "Role.h"


class User 
{
private:

    bool loggedIn;
    std::string username;
    std::string password;
    Role role;

public:

    User();
    bool addUser(const std::string& uname, const std::string& pwd, const std::string& rl); // makes a new user will return true if they were added successfully and false if not
    bool login(const std::string& uname, const std::string& pwd); // will take username and password and return true if they can be logged in and false if not
    std::string getUsername(); // will get the username  
    void changeRole(std::string& rl); // will change the role 
    bool isLoggedIn(); // will return true if logged in and false if not
    std::string getRoleName() ; // this will give you the users role 
    const Role& getRole() ; //this is a reference to the role class to access its member functions

    bool checkPermission(const std::string& action) const;// check permission
};
