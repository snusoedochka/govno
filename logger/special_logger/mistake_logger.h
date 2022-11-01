#ifndef MISTAKE_LOGGER_H
#define MISTAKE_LOGGER_H
#include "../logger_level.h"
#include "../special_messages/mistake_message.h"

class mistake_logger: public logger_level{
public:
    mistake_logger();
    std::string send(message * message) override;
    ~mistake_logger() override;
};

#endif //MISTAKE_LOGGER_H
