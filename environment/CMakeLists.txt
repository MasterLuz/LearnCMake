cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(environment LANGUAGES CXX)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Configuring on/for Linux")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    message(STATUS "Configuring on/for Darwin")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message(STATUS "Configuring on/for Windows")
elseif(CMAKE_SYSTEM_NAME STREQUAL "AIX")
    message(STATUS "Configuring on/for AIX")
else()
    message(STATUS "Configuring on/for ${CMAKE_SYSTEM_NAME}")
endif()

add_executable(hello hello.cpp)

target_compile_definitions(hello PUBLIC
    "COMPILER_NAME=\"${CMAKE_CXX_COMPILER_ID}\""
)

if(CMAKE_CXX_COMPILER_ID MATCHES Intel)
    target_compile_definitions(hello PUBLIC "IS_INTEL_CXX_COMPILER")
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    target_compile_definitions(hello PUBLIC "IS_GNU_CXX_COMPILER")
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES PGI)
    target_compile_definitions(hello PUBLIC "IS_PGI_CXX_COMPILER")
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES XL)
    target_compile_definitions(hello PUBLIC "IS_XL_CXX_COMPILER")
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES MSVC)
    target_compile_definitions(hello PUBLIC "IS_MSVC_CXX_COMPILER")
endif()

if(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "i386")
    message(STATUS "i386 architecture detected")
elseif(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "i686")
    message(STATUS "i686 architecture detected")
elseif(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "x86_64")
    message(STATUS "x86_64 architecture detected")
elseif(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "AMD64")
    message(STATUS "AMD64 architecture detected")
else()
    message(STATUS "host processor architecture is unknown")
endif()
target_compile_definitions(hello
    PUBLIC "ARCHITECTURE=\"${CMAKE_HOST_SYSTEM_PROCESSOR}\""
)
