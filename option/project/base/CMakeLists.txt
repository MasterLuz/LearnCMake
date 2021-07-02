cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

include(CMakeDependentOption)

set(SOURCE_PATH ../../src)
set(ProjectName option)
#set(BUILD_SHARED_LIBS OFF)
#set(USE_LIBRARY OFF)

option(USE_LIBRARY "Compile sources into a library" OFF)

cmake_dependent_option(
    MAKE_STATIC_LIBRARY "Compile sources into a static library" ON
    "USE_LIBRARY" ON
)

cmake_dependent_option(
    MAKE_SHARED_LIBRARY "Compile sources into a shared library" OFF
    "USE_LIBRARY" ON
)

project(${ProjectName} LANGUAGES CXX)

list(APPEND 
    MessageSources 
        ${SOURCE_PATH}/message/Message.h
        ${SOURCE_PATH}/message/Message.cpp
)

if(USE_LIBRARY)
    add_library(message STATIC ${MessageSources})
    add_executable(helloWorld ${SOURCE_PATH}/helloWorld.cpp)
    target_link_libraries(helloWorld message)
else()
    add_executable(helloWorld 
        ${SOURCE_PATH}/helloWorld.cpp
        ${SOURCE_PATH}/message/Message.h
        ${SOURCE_PATH}/message/Message.cpp
    )
endif()
