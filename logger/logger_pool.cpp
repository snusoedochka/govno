#include "logger_pool.h"
logger_pool::logger_pool()
{}

void logger_pool::addLogger(logger * logger)
{
    loggers.push_back(logger);
}

void logger_pool::removeLogger()
{
    loggers.pop_back();
}

logger_pool::~logger_pool()
{
    for (auto lg:loggers) {
        delete lg;
    }
    for (auto lv:levels) {
        delete lv;
    }
}

void logger_pool::addLevel(logger_level *level)
{
    levels.push_back(level);
}

void logger_pool::update(message *message)
{
    for (auto lg: loggers) {
        for (auto lv: levels) {
            auto temp = lv->send(message);
            if (temp != "") {
                lg->print(temp);

            }
        }
    }
    delete message;
}

void logger_pool::config()
{
    /*file_logger cleaner("C:/Users/romas/Desktop/new_2-master/logger/logs.txt");
    cleaner.clear();*/
    std::cout << "enter loggers and levels you want to use (1st line - loggers, 2nd line - levels)" << std::endl;
    std::string loggers_, levels_;
    std::getline(std::cin,loggers_);
    std::getline(std::cin, levels_);
    if (loggers_.find("console") != std::string::npos)
        this->addLogger(new console_logger());
    if (loggers_.find("file") != std::string::npos)
        this->addLogger(new file_logger("C:/Users/romas/Desktop/new_2-master/logger/logs.txt"));
    if (levels_.find("event") != std::string::npos) this->addLevel(new event_logger());
    if (levels_.find("game") != std::string::npos) this->addLevel(new game_logger());
    if (levels_.find("mistake") != std::string::npos) this->addLevel(new mistake_logger());
}