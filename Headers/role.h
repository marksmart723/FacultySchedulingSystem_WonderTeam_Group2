#pragma once

#include <string>
#include <vector>
#include <map>
#include <iostream>

//std::vector<std::string> regFac = { "View My Schedule", "Request Changes" };
//std::vector<std::string> tempFac = { "View My Schedule"};
//std::vector<std::string> DepChair = { "Create a Schedule", "Modify a Schedule" };
//std::vector<std::string> Dean = { "View all Schedules", "Generate Reports" };
//std::map < std::string, std::vector<std::string>> perm{ {"Regular Faculty", regFac}, {"Temporary Faculty", tempFac},
//??????????????????????????????????????????????????????????????????????????????????{"Department Chair", DepChair}, {"Dean", Dean} };


enum roleName
{
	RegularFaculty, TemporaryFaculty, DepartmentChair, Dean
};

class Role
{
private:
	std::string role;
	unsigned id;
	std::vector<std::string> permitionNames;
	std::vector<bool> permitions;
	std::map<std::string, roleName> roleMap;

public:
	Role() { role = "Not Logged In"; }
	Role(std::string r)
	{
		role = r;
		roleMap = { {"Regular Faculty", RegularFaculty}, {"Temporary Faculty", TemporaryFaculty}, {"Department Chair", DepartmentChair}, {"Dean", Dean} };
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
			//default:
				  //std::cout << "Not a valid role" << std::endl;
		}



	}




};