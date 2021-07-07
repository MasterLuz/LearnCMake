# environment 

## 判断平台
```cmake
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Configuring on/for Linux")
    target_compile_definitions(hello PUBLIC "IS_LINUX")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin") 
    message(STATUS "Configuring on/for Darwin")
    target_compile_definitions(hello PUBLIC "IS_MACOS")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message(STATUS "Configuring on/for Windows")
    target_compile_definitions(hello PUBLIC "IS_WINDOWS")
elseif(CMAKE_SYSTEM_NAME STREQUAL "AIX")
    message(STATUS "Configuring on/for AIX")
    target_compile_definitions(hello PUBLIC "IS_LINUX")
else()
    message(STATUS "Configuring on/for ${CMAKE_SYSTEM_NAME}")
endif()
```
- 注意这里`STREQUAL`用于判断字符串相等
- `target_compile_definitions`可以给目标增加宏定义（全局的，不需要include）

## 检测编译器
```cmake
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
```
- 请注意本例中是如何把COMPILER_NAME定义成`const char*`类型的
- `CMAKE_CXX_COMPILER_ID`指定了编译器类型

## 检测架构
```cmake
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
```
- `CMAKE_HOST_SYSTEM_PROCESSOR`表示CMake当前运行的机器的架构
- `CMAKE_HOST_SYSTEM_PROCESSOR`表示CMake构建目标运行的机器的架构

## 检测平台参数
```cpp
// config.h.in
#define NUMBER_OF_LOGICAL_CORES     @_NUMBER_OF_LOGICAL_CORES@
#define NUMBER_OF_PHYSICAL_CORES    @_NUMBER_OF_PHYSICAL_CORES@
#define TOTAL_VIRTUAL_MEMORY        @_TOTAL_VIRTUAL_MEMORY@
#define AVAILABLE_VIRTUAL_MEMORY    @_AVAILABLE_VIRTUAL_MEMORY@
#define TOTAL_PHYSICAL_MEMORY       @_TOTAL_PHYSICAL_MEMORY@
#define AVAILABLE_PHYSICAL_MEMORY   @_AVAILABLE_PHYSICAL_MEMORY@
#define IS_64BIT                    @_IS_64BIT@
#define HAS_FPU                     @_HAS_FPU@
#define HAS_MMX                     @_HAS_MMX@
#define HAS_MMX_PLUS                @_HAS_MMX_PLUS@
#define HAS_SSE                     @_HAS_SSE@
#define HAS_SSE2                    @_HAS_SSE2@
#define HAS_SSE_FP                  @_HAS_SSE_FP@
#define HAS_SSE_MMX                 @_HAS_SSE_MMX@
#define HAS_AMD_3DNOW               @_HAS_AMD_3DNOW@
#define HAS_AMD_3DNOW_PLUS          @_HAS_AMD_3DNOW_PLUS@
#define HAS_IA64                    @_HAS_IA64@
#define OS_NAME                     "@_OS_NAME@"
#define OS_RELEASE                  "@_OS_RELEASE@"
#define OS_VERSION                  "@_OS_VERSION@"
#define OS_PLATFORM                 "@_OS_PLATFORM@"
```

## 输出消息的特殊形式
```cmake
message(CHECK_START "Finding my things")
list(APPEND CMAKE_MESSAGE_INDENT "  ")
unset(missingComponents)

message(CHECK_START "Finding partA")
# ... do check, assume we find A
message(CHECK_PASS "found")

message(CHECK_START "Finding partB")
# ... do check, assume we don't find B
list(APPEND missingComponents B)
message(CHECK_FAIL "not found")

list(POP_BACK CMAKE_MESSAGE_INDENT)
if(missingComponents)
  message(CHECK_FAIL "missing components: ${missingComponents}")
else()
  message(CHECK_PASS "all components found")
endif()
```