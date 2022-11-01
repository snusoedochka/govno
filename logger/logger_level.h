#ifndef LOGGER_LEVEL_H
#define LOGGER_LEVEL_H
#include "message.h"

class logger_level {
public:
    virtual std::string send(message * message) = 0;
    virtual ~logger_level() = 0;
};


#endif //LOGGER_LEVEL_H
