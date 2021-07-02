# option

## CMake语法

1. `set(A B)`, 将变量A的值设置为B，其中A可以是自定义变量，可以是CMake定义的变量
1. `set(BUILD_SHARED_LIBS OFF)`, 这里BUILD_SHADRED_LIBS是CMake定义的变量，作为add_library(lib type source)中`type`的默认值。
1. `option(USE_LIBRARY "Compile sources into a library" OFF)`, 表示定义一个用户指定的变量`USE_LIBRARY`，他的描述是双引号中的字符串（可以再CMake GUI中看到）， 默认值是OFF

## CMake命令
1. `cmake . -D USE_LIBRARY=ON`, 通过这种方式可以指定option USE_LIBRARY的值，指定的另一种方式是通过CMake GUI。

## Depend Option
如果某个option依赖于另一个，那么就需要使用这个功能。
1. 首先要`include(CMakeDependentOption)`
1. 其次
```
cmake_dependent_option(
    MAKE_STATIC_LIBRARY "Compile sources into a static library" ON
    "USE_LIBRARY" ON
)
```
表示`MAKE_STATIC_LIBRARY`变量依赖于`USE_LIBRARY`变量，如果`USE_LIBRARY`为ON，则MAKE_STATIC_LIBRARY有默认值ON,否则这个变量未定义