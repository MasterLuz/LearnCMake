#ifndef MESSAGE_H__
#define MESSAGE_H__

#include <iosfwd>
#include <string>

class Message{
public:
    Message(const std::string& m):message_(m){}

    friend std::ostream& operator<<(std::ostream& os, Message& obj){
        return obj.printObject(os);
    }

private:
    std::ostream& printObject(std::ostream& os);

    std::string message_;
};

#endif//MESSAGE_H__