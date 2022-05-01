cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

add_definitions(-std=c++11)

set(CXX_FLAGS "")
set(CMAKE_CXX_FLAGS "${CXX_FLAGS}")

set(CMAKE_BUILD_TYPE Debug)

project(Project_OOP)

add_executable(
    Project_OOP
    main.cpp
    Component.cpp
    Shop.cpp
    CLIController.cpp
    CLIApp.cpp
        FileHandler.cpp FileHandler.h)