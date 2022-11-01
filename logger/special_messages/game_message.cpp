#include "game_message.h"

game_message::game_message(){
    message_ = "[GAME]";
}

game_message::game_message(std::string m) {
    message_ = "[GAME]" + m;
}

std::string game_message::getMessage() const {
    return message_;
}

std::ostream &operator<<(std::ostream &out, const game_message& m)
{
    out << m.message_ << std::endl;
    return out;
}

game_message::~game_message(){}