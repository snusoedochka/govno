#include "console_logger.h"

void console_logger::print(std::string message)
{
    std::cout << message;
}

console_logger::~console_logger()
{}