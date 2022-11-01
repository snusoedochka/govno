#include "game_logger.h"


game_logger::game_logger() {}

std::string game_logger::send(message *message) {
    game_message* game_temp = dynamic_cast<game_message*>(message);
    if(game_temp != nullptr){
        return game_temp->getMessage();
    }
    return "";
}
game_logger::~game_logger(){}