#include "file_logger.h"

void file_logger::print(std::string message)
{
    file << message;
}

file_logger::file_logger(std::string filename)
{
    filename_ = filename;
    file.open(filename_);
}

file_logger::~file_logger()
{
    file.close();
}