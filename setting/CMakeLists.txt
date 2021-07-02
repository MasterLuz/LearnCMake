cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(ProjectName setting)
set(CMAKE_CXX_STANDARD 17)

project(${ProjectName})

add_executable(${ProjectName} helloWorld.cpp)