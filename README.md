# LearnCMake

这里记录一些平时看到的cmake指令，之后整理到对应章节中

## include_directory

### `include_directoriess([AFTER|BEFORE] [SYSTEM] dir1 [dir2 ...])`
前两个选项很少用，可以忽略，用于添加包含目录给整个CMakeLists.txt中包含的项目及sub_directory中的项目，
比如你在CMakeLists.txt中这样写
```cmake
include_directories(AFTER include/lua)
```
那么你在C++源文件中就可以这样引用`include/lua`目录下的头文件,而不用管相对路径
```c++
include <lua.h>
```

### `target_include_directories(target [SYSTEM] [AFTER|BEFORE] <INTERFACE|PUBLUIC|PRIVATE> [iterms1...])`
example:
```cmake
add_library(lib lib.c)
add_executable(test test.c)
target_link_lirbaries(test lib)
target_include_directories(test
    PUBLIC include/aaa
    PRIVATE include/bbb
)
```
功能类似`include_directoriess`，但是只会添加到指定的target上。如上例中，aaa和bbb目录并不会添加到lib的包含目录中
> CMake更推荐是用带`target_include_directories`而不是`include_directoriess`

## 流程控制


## Visual Studio相关
### `source_group(<name> [FILES <src>...] [REGULAR_EXPRESSION <regex>])`
将一些文件（可以直接指定或者用正则表达式搜集）放在Visual Studio解决方案中的同一个筛选器下
### `source_group(TREE <root> [PREFIX <prefix>] [FILES <src>...])`
> 注意，`TREE`和`PREFIX`要求CMake版本高于3.8
具体效果待研究！

## File
### file({GLOB | GLOB_RECURSE} <out_var> [...] [<globbing-expr>...])
用于将满足后方表达式的文件全部存入`<out_var>`中
- GLOB 表示当前目录下的文件
- GLOB_RECURSE 表示递归搜索该目录下所有文件

## Microsoft Visual Studio相关设置

### 设置启动项
启动项就是指Visual Studio中默认F5运行的项目（这在多项目解决方案中比较重要）
```cmake
# ----------------------------------------
# Microsoft Visual Studio settings
# ----------------------------------------
if(MSVC)
    if(NOT ${CMAKE_VERSION} VERSION_LESS "3.6.0")
        set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME}
        )
    endif()
endif(MSVC)
```

### 设置工作目录
工作目录就是你程序运行的目录，典型的比如你的文件读取的根目录
```cmake
set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)
```

### 设置项目文件目录
你可以把项目进行分类放好，可读性更强
```cmake
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_target_properties(${PROJECT_NAME} PROPERTIES
   FOLDER "LuaTest"
)
```

### 设置BuildType
编译器分为支持多个config的（如Visual Studio），和单个的。支持多个代表你可以像Visual Studio项目一样，修改是生成Debug还是Release
```
if(CMAKE_CONFIGURATION_TYPES)   #multiconfig generator?
    set(CMAKE_CONFIGURATION_TYPES) "Debug; Release;" CACHE STRING "" FORCE
else()
    if(NOT CMAKE_BUILD_TYPE)
        message("Defaulting to release build.")
        set(CMAKE_BUILD_TYPE Release CACHE STRING "" FORCE)
    endif()
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY HELPSTRING "Choose the type of build")
    # set the valid options for cmake-gui drop-down list
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug;Release;Profile")
endif()
```

## 其他
### 给Debug和Release指定不同的库目录
`target_link_libraries(project debug ${debug_path}/LibName) release ${release_path}/LibName`


