#include "role.h"

Role::Role(std::string r)
{
	role = r;
	roleMap = { {"RegFaculty", RegularFaculty}, {"TempFaculty", TemporaryFaculty}, {"Chair", DepartmentChair}, {"Dean", Dean} };
	id = roleMap[r];
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