#include "Message.h"

#include <iostream>
#include <string>

std::ostream& Message::printObject(std::ostream& os){
    os << "This is my very nice message:" << "\n";
    os << message_ << std::endl;
    return os;
}