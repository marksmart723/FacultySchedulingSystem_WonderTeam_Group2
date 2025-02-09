cmake_minimum_required(VERSION 3.30)
project(FacultySchedulingSystem_WonderTeam_Group2)

set(CMAKE_CXX_STANDARD 14)

include_directories(Headers)

add_executable(FacultySchedulingSystem_WonderTeam_Group2
    Headers/menu.h
    Headers/role.h
    Headers/user.h
    Source/main.cpp
    Source/menu.cpp
    Source/role.cpp
    Source/user.cpp)
