#include "event_message.h"

event_message::event_message(){
    message_ = "[EVENT]";
}

event_message::event_message(std::string m) {
    message_ = "[EVENT]" + m;
}

std::string event_message::getMessage() const {
    return message_;
}

std::ostream &operator<<(std::ostream &out, const event_message& m)
{
    out << m.message_ << std::endl;
    return out;
}

event_message::~event_message(){}