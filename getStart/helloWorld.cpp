#include <iostream>
#include <cstdlib>
#include <string>

static std::string sayHello(){
    return std::string("Hello, CMake world!");
}

int main(){
    std::cout << sayHello() << std::endl;
    return EXIT_SUCCESS;
}