# setting

## 指定CMake C++版本
### 修改Makefile(CMake生成的)
```
CFLAGS += -std=c++17
```

### CMakeLists.txt中增加
```
set(CMAKE_CXX_STANDARD 17)
```
更好的做法：
```cmake
set_target_properties(project PROPERTIES
    CXX_STANDARD 17             # c++语言标准
    CXX_EXTENSIONS OFF          # 只是用ISOc++标准，不使用各个编译器的扩展
    CXX_STANDARD_REQUIRED ON    # 表示该标准是必须的，如果没有提供C++17的标准， 那么会报错
)
```

### 调用CMake时附加参数
```
cmake -DCMAKE_CXX_STANDARD=17
```

### 指定更详细的语言特性
有时我们不想指定整个语言标准，而是某一个语法特性
```cmake
target_compile_features()
```

## 增加编译选项
```cmake
list(APPEND flags "-fPIC" "-Wall")
add_executable(project test.cpp)
target_compile_options(project PRIVATE ${flags})
```
或者这样
```
cmake -D CMAKE_CXX_FLAGS="-fno-exceptions -fno-rtti"
```

## VERBOSE
有的时候我们想要打印更加详细的CMake生成信息来帮助调试
```cmake
cmake --build. --VERBOSE=1
```

