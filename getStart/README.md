# Get Start
## CMake 语法
1. `cmake_minimum_required(VERSION 3.5 FATAL_ERROR)`, 指定CMake版本，`FATAL_ERROR`表示版本小于3.5将会报错
1. `set(ProjectName getStart)`, 设置变量，这里设置了`ProjectName`等于`getStart`。这里`ProjectName`是用户自定义变量
1. `project(${ProjectName})`, 指定项目名称
1. `add_executable(${ProjectName} helloWorld.cpp)`, 给`${ProjectName}`项目添加`helloWorld.cpp`为源文件之一

## CMake 命令
1. `cmake -H. -Bbuild`, 以`.`为根目录，以`build`为生成目录
1. `cmake --build build`, 以`build`为构建根目录，构建项目
1. `cmake --help`, 生成帮助文件
1. `cmake --build build --target <target-name>`, 指定目标生成的项目名（有的CMake项目中有多个项目）
    > 其实即使是本项目也可以有多个构建目标名：(Visual Studio平台)
    > 1. getStart
    > 1. getStart.o （可以指定构建出中间文件）
    > 1. ALL_BUILD
    > 1. ZERO_CHECK
    > 除了`getStart.o`，其他几个项目名你都可以在使用直接构建（不指定target）时看到，这就是Visual Studio CMake项目默认给我们生成的几个项目
1. `cmake -G "Visual Studio 16 2019" -A x64`, 表示以`Visual Studio 2019` 作为生成器， 生成64位的项目

## 一些知识点
1. CMake的build目录包含一些文件，这里讲了各自的含义
    > | File | Usage |
    > | - | - |
    > | CMakeCache.txt | CMake自己生成的一些缓存 |
    > | CMakeFiles | CMake设置时生成的一些临时文件|
    > | cmake_install.cmake | CMake脚本install时运行的install规则|