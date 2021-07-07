cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(environment LANGUAGES CXX)

add_executable(hello)

# compile option
# -----------------------------------------------------
# detect system(Linux, Darwin, Windows, AIX...)
message(STATUS "Configuring on/for ${CMAKE_SYSTEM_NAME}")
target_compile_definitions(hello PUBLIC "SYSTEM_NAME=\"${CMAKE_SYSTEM_NAME}\"")
target_compile_definitions(hello PUBLIC "SYSTEM_${CMAKE_SYSTEM_NAME}")

# detect compiler(Intel, GNU, PGI, XL, MSVC...)
message(STATUS "Configuring on/for ${CMAKE_CXX_COMPILER_ID}")
target_compile_definitions(hello PUBLIC "CXX_COMPILER_NAME=\"${CMAKE_CXX_COMPILER_ID}\"")
target_compile_definitions(hello PUBLIC "CXX_COMPILER_${CMAKE_CXX_COMPILER_ID}")

# detect architecture(i386, i686, x86_64, AMD64...)
message(STATUS "Configuring on/for ${CMAKE_HOST_SYSTEM_PROCESSOR}")
target_compile_definitions(hello PUBLIC "ARCHITECTURE=\"${CMAKE_HOST_SYSTEM_PROCESSOR}\"")
target_compile_definitions(hello PUBLIC "ARCHITECTURE_${CMAKE_HOST_SYSTEM_PROCESSOR}")

# config file
# -----------------------------------------------------
# detect host system information
set(SYSTEM_INFORMATION_LOOKUP_LIST 
    NUMBER_OF_LOGICAL_CORES
    NUMBER_OF_PHYSICAL_CORES
    TOTAL_VIRTUAL_MEMORY
    AVAILABLE_VIRTUAL_MEMORY
    TOTAL_PHYSICAL_MEMORY
    AVAILABLE_PHYSICAL_MEMORY
    IS_64BIT
    HAS_FPU
    HAS_MMX
    HAS_MMX_PLUS
    HAS_SSE
    HAS_SSE2
    HAS_SSE_FP
    HAS_SSE_MMX
    HAS_AMD_3DNOW
    HAS_AMD_3DNOW_PLUS
    HAS_IA64
    OS_NAME
    OS_RELEASE
    OS_VERSION
    OS_PLATFORM
)

foreach(lookupItem ${SYSTEM_INFORMATION_LOOKUP_LIST})
    cmake_host_system_information(RESULT _${lookupItem} QUERY ${lookupItem})
endforeach()

configure_file(config.h.in config.h @ONLY)

# sources
# -----------------------------------------------------
target_sources(hello PRIVATE hello.cpp)

# includes
# -----------------------------------------------------
target_include_directories(hello PRIVATE ${PROJECT_BINARY_DIR})