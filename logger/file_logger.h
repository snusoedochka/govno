#ifndef FILE_LOGGER_H
#define FILE_LOGGER_H

#include "logger.h"
#include <fstream>

class file_logger: public logger {
public:
    file_logger(std::string filename);
    void print(std::string message) override;
    ~file_logger() override;
private:
    std::string filename_;
    std::ofstream file;
};


#endif //FILE_LOGGER_H
