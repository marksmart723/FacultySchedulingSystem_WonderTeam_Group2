#include "role.h"

Role::Role()
{
    role = "TempFaculty";
    roleMap = { {"RegFaculty", RegularFaculty}, {"TempFaculty", TemporaryFaculty}, {"Chair", DepartmentChair}, {"Dean", Dean} };
	id = roleMap[role];
    permitions = { 1, 0, 0, 0, 0, 0 };
    permitionNames = { "View My Schedule", "Request Changes", "Create a Schedule", "Modify a Schedule", "View all Schedules", "Generate Reports" };

}

Role::Role(std::string rName)
{
	role = rName;
	roleMap = { {"RegFaculty", RegularFaculty}, {"TempFaculty", TemporaryFaculty}, {"Chair", DepartmentChair}, {"Dean", Dean} };
	id = roleMap[rName];
	permitionNames = { "View My Schedule", "Request Changes", "Create a Schedule", "Modify a Schedule", "View all Schedules", "Generate Reports" };

	switch (id)
	{
	case 0:
		permitions = { 1, 1, 0, 0, 0, 0 };
		break;
	case 1:
		permitions = { 1, 0, 0, 0, 0, 0 };
		break;
	case 2:
		permitions = { 0, 0, 1, 1, 0, 0 };
		break;
	case 3:
		permitions = { 0, 0, 0, 0, 1, 1 };
		break;
	default:
		std::cout << "Not a valid role" << std::endl;
	}

}

std::vector<std::string> Role::getPermitions()
{
	std::vector<std::string> toReturn;
	for (int i = 0; i < permitionNames.size(); i++)
	{
		if (permitions[i] == 1)
		{
			toReturn.push_back(permitionNames[i]);
		}
	}
	return toReturn;
}

std::string Role::getRole() const
{
	return role;
}