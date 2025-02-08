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
	std::string role;							// name of the Role (should match exactly the role name in data text file)
	unsigned id;								// role id according to enum oleName
	std::vector<std::string> permissionNames;	// vector with permission names
	std::vector<bool> permissions;				// vector with bool values according to existing permissions for the role
	std::map<std::string, roleName> roleMap;	// maps std::string role with role id

public:
    // default constructor, creates an empty Role object with no permissions 
    Role();
    // parametrized constructor, uses string rName representing the role to create a Role object with the according permissions 
	Role(std::string);
	
    // accessor. Returns a const vector of strings of permissions
	const std::vector<std::string> getPermissions() const;
	
	// accessor. Returns a const string with the current Role
	const std::string getRole() const;

	// takes a string newRole as argument, updates the role and permissions
	bool changeRole(std::string);

};

#endif // !_ROLE_H
