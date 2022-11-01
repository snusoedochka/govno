#ifndef EVENT_MESSAGE_H
#define EVENT_MESSAGE_H
#include "../message.h"

class event_message: public message{
public:
    event_message();
    event_message(std::string m);
    std::string getMessage() const;
    ~event_message() override;
    friend std::ostream& operator<<(std::ostream& out, const event_message& m);

private:
    std::string message_;
};


#endif //EVENT_MESSAGE_H
