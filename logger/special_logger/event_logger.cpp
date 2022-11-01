#include "event_logger.h"

event_logger::event_logger() {}

std::string event_logger::send(message *message) {
    event_message* event_temp = dynamic_cast<event_message*>(message);
    if(event_temp != nullptr){
        return event_temp->getMessage();
    }
    return "";
}
event_logger::~event_logger(){}