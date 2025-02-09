#include "role.h"
#include <stdexcept>

Role::Role()	//  creates an empty Role object with no permissions
{
    role = "";
    roleMap = { {"RegFaculty", RegularFaculty}, {"TempFaculty", TemporaryFaculty}, {"Chair", DepartmentChair}, {"Dean", Dean} };
	id = -1;
    permissions = { 0, 0, 0, 0, 0, 0 };
    permissionNames = { "View My Schedule", "Request Changes", "Create a Schedule", "Modify a Schedule", "View all Schedules", "Generate Reports" };

}

Role::Role(std::string rName)
{
	
	roleMap = { {"RegFaculty", RegularFaculty}, {"TempFaculty", TemporaryFaculty}, {"Chair", DepartmentChair}, {"Dean", Dean} };
	try
	{
		id = roleMap[rName];
		
	}
	catch(const std::exception& e)	// throws exception if the Role is invalid
	{
		std::cerr << e.what() << '\n';
	}
	
	role = rName;
	permissionNames = { "View My Schedule", "Request Changes", "Create a Schedule", "Modify a Schedule", "View all Schedules", "Generate Reports" };
	// assignes approptiate permitions for the role
	switch (id)
	{
	case 0:
		permissions = { 1, 1, 0, 0, 0, 0 };	// RegFaculty : View My Schedule, Request Changes
		break;
	case 1:
		permissions = { 1, 0, 0, 0, 0, 0 };	// TempFaculty : View My Schedule
		break;
	case 2:
		permissions = { 0, 0, 1, 1, 0, 0 };	// Chair : Create a Schedule, Modify a Schedule
		break;
	case 3:
		permissions = { 0, 0, 0, 0, 1, 1 };	// Dean : View all Schedules, Generate Reports
		break;
	default:
		std::cout << "Not a valid role" << std::endl;
	}

}

// accessor. Returns a const vector of strings of permitions
const std::vector<std::string> Role::getPermissions() const
{
	std::vector<std::string> toReturn;		// creates an empty vector
	for (int i = 0; i < permissionNames.size(); i++)
	{
		if (permissions[i] == 1)				// populates vector toReturn with appropriate permitions 
		{
			toReturn.push_back(permissionNames[i]);
		}
	}
	return toReturn;
}

// accessor. Returns a const string with the current Role
const std::string Role::getRole() const
{
	return role;
}

bool Role::changeRole(std::string newRole)
{
	if (role != newRole)
	{
		try
		{
			id = roleMap[newRole];		
		}
		catch(const std::exception& e)	// throws exception if the Role is invalid
		{
			std::cerr << e.what() << '\n';
		}
		role = newRole;

		switch (id)
		{
		case 0:
			permissions = { 1, 1, 0, 0, 0, 0 };	// RegFaculty : View My Schedule, Request Changes
			break;
		case 1:
			permissions = { 1, 0, 0, 0, 0, 0 };	// TempFaculty : View My Schedule
			break;
		case 2:
			permissions = { 0, 0, 1, 1, 0, 0 };	// Chair : Create a Schedule, Modify a Schedule
			break;
		case 3:
			permissions = { 0, 0, 0, 0, 1, 1 };	// Dean : View all Schedules, Generate Reports
			break;
		default:
			std::cout << "Not a valid role" << std::endl;
		}
		return true;
	}
	else
	{
		return true;
	}
}