#ifndef LOGGER_H
#define LOGGER_H

#include "Message.h"

class logger {
public:
    virtual void print(std::string message) = 0;
    virtual ~logger() = 0;
};

#endif//LOGGER_H