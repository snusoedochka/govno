#ifndef LOGGER_POOL_H
#define LOGGER_POOL_H
#include <vector>
#include "observer/observer.h"
#include "logger_level.h"
#include "console_logger.h"
#include "file_logger.h"
#include "special_logger/game_logger.h"
#include "special_logger/mistake_logger.h"
#include "special_logger/event_logger.h"

class logger_pool: public observer {
public:
    logger_pool();
    void update(message * message) override;
    void addLogger(logger * logger);
    void removeLogger();
    void addLevel(logger_level * level);
    void config();
    ~logger_pool();
private:

    std::vector<logger_level *> levels;
    std::vector<logger *> loggers;
};


#endif //LOGGER_POOL_H
