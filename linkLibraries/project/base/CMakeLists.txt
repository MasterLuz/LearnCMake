cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(ProjectName linkLibraries)
set(SOURCE_PATH ../../src)

project(${ProjectName})

add_library(message 
    STATIC
        ${SOURCE_PATH}/message/Message.h
        ${SOURCE_PATH}/message/Message.cpp
    )

add_executable(${ProjectName} ${SOURCE_PATH}/helloWorld.cpp)

target_link_libraries(${ProjectName} message)