#ifndef EVENT_LOGGER_H
#define EVENT_LOGGER_H
#include "../logger_level.h"
#include "../special_messages/event_message.h"

class event_logger: public logger_level{
public:
    event_logger();
    std::string send(message * message) override;
    ~event_logger() override;
};

#endif //EVENT_LOGGER_H
