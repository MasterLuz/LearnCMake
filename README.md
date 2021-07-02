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


