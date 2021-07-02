#include <iostream>
#include <cstdlib>
#include <string>

#include "message/Message.h"

int main(){
    Message sayHello("Hello, CMake World");
    std::cout << sayHello << std::endl;
    Message sayGoodbye("Goodbye, CMake World");
    std::cout << sayGoodbye << std::endl;
    return EXIT_SUCCESS;
}