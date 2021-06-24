  # linkLibraries

  ## CMake语法
  1. `add_library(message STATIC Message.h Message.cpp)`，这条语句会把Message.h, Message.cpp编译成一个lib文件供其他项目使用，lib的类型有很多种：
        > | type | 类型 | 描述 |
        > | - | - | - | 
        > |STATIC   |静态库|在windows上相当于生成.lib文件|
        > |SHARED   |动态库|在windows上相当于生成.dll文件|
        > |OBJECT   |中间代码库|如果你想要同时生成静态库和动态库，而又不想生成中间文件两边，可以使用这个功能|
        > |MODULE   |动态库|与SHARED不同，这个是运行时插件（未测试）|
        > |IMPORTED |外部库|未测试|
        > |INTERFACE|移动的外部库|未测试|
        > |ALIAS    | 别名库|未测试|
  1. `target_link_libraries(linkLibraries message)`，链接message库到linkLibraries可执行项目上，并且确保message会在linkLibraries前编译

  ## 代码结构介绍
  因为本节使用了同样的源码，而使用不同的CMakeLists.txt，故而CMake文件及其build放在了project目录下，project下项目介绍
  | 目录 | 描述 |
  | - | - |
  | base | 构建基本的静态库|
  | object | 使用Object目标同时构建静态库和动态库|
