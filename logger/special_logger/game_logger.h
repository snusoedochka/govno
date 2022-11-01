#ifndef GAME_LOGGER_H
#define GAME_LOGGER_H
#include "../logger_level.h"
#include "../special_messages/game_message.h"

class game_logger: public logger_level{
public:
    game_logger();
    std::string send(message * message) override;
    ~game_logger() override;
};

#endif //GAME_LOGGER_H
