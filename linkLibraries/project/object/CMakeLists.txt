cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(SOURCE_PATH ../../src)
set(ProjectName linkLibraries)

project(${ProjectName} LANGUAGES CXX)

add_library(message-objs
    OBJECT
        ${SOURCE_PATH}/message/Message.h
        ${SOURCE_PATH}/message/Message.cpp
    )

add_library(message-shared
    SHARED
        $<TARGET_OBJECTS:message-objs>
)

set_target_properties(message-shared
    PROPERTIES
        OUTPUT_NAME "message"
)

add_library(message-static
    STATIC
        $<TARGET_OBJECTS:message-objs>
)

set_target_properties(message-static
    PROPERTIES
        OUTPUT_NAME "message"
)

add_executable(${ProjectName} 
    ${SOURCE_PATH}/helloWorld.cpp
)

target_link_libraries(${ProjectName}
    message-static 
)