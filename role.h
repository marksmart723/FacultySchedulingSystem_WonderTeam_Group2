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
	Role(std::string r);
	

	std::vector<std::string> getPermitions();
	

};

#endif // !_ROLE_H