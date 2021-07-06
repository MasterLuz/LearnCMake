#include <iostream>

int main(){
    std::cout << "hello" << std::endl;
    std::cout << COMPILER_NAME << std::endl;
    std::cout << typeid(COMPILER_NAME).name() << std::endl;
#ifdef IS_MSVC_CXX_COMPILER
    std::cout << "yes, MSVC" << std::endl;
#endif
    std::cout << ARCHITECTURE << std::endl;
}