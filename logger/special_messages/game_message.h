#ifndef GAME_MESSAGE_H
#define GAME_MESSAGE_H
#include "../message.h"

class game_message: public message{
public:
    game_message();
    game_message(std::string m);
    std::string getMessage() const;
    ~game_message() override;
    friend std::ostream& operator<<(std::ostream& out, const game_message& m);

private:
    std::string message_;
};


#endif //GAME_MESSAGE_H