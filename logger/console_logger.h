#ifndef CONSOLE_LOGGER_H
#define CONSOLE_LOGGER_H
#include "logger.h"

class console_logger:public logger{
public:
    void print(std::string message) override;
    ~console_logger() override;
};


#endif //CONSOLE_LOGGER_H
