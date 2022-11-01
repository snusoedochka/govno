#ifndef FILE_LOGGER_H
#define FILE_LOGGER_H

#include "logger.h"
#include <fstream>

class file_logger: public logger {
public:
    void clear();
    //friend std::ostream& operator<<(std::fstream& stream, file_logger& obj);
    file_logger(std::string filename);
    void print(std::string message) override;
    ~file_logger() override;
private:
    std::string filename_;
    std::fstream file;
    //std::string message;
};


#endif //FILE_LOGGER_H
