#ifndef _ROLE_H
#define _ROLE_H

#include <string>
#include <vector>
#include <map>
#include <iostream>

enum roleName
{RegularFaculty,TemporaryFaculty,DepartmentChair,Dean};

class Role
{
private:
	std::string role;
	unsigned id;
	std::vector<std::string> permitionNames;
	std::vector<bool> permitions;
	std::map<std::string, roleName> roleMap;

public:
    // default constructor, creates a Role object with minimum permitions (TempFaculty)
    Role();
    // parametrized constructor, uses string rName representing the role to create a Role object with the according permitions 
	Role(std::string);
	
    // accessor. Returns a vector of strings of permittions
	std::vector<std::string> getPermitions();
	
	// accessor. Returns a string with the current Role
	std::string getRole() const;

};

#endif // !_ROLE_H