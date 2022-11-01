#include "mistake_logger.h"

mistake_logger::mistake_logger() {}

std::string mistake_logger::send(message *message) {
    mistake_message* mistake_temp = dynamic_cast<mistake_message*>(message);
    if(mistake_temp != nullptr){
        return mistake_temp->getMessage();
    }
    return "";
}
mistake_logger::~mistake_logger(){}