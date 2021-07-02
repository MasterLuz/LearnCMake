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

### 调用CMake时附加参数
```
cmake -DCMAKE_CXX_STANDARD=17
```