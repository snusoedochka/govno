#include "mistake_message.h"

mistake_message::mistake_message(){
    message_ = "[MISTAKE]";
}

mistake_message::mistake_message(std::string m) {
    message_ = "[MISTAKE]" + m;
}

std::string mistake_message::getMessage() const {
    return message_;
}

std::ostream &operator<<(std::ostream &out, const mistake_message& m)
{
    out << m.message_ << std::endl;
    return out;
}

mistake_message::~mistake_message(){}