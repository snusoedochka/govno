#ifndef MISTAKE_MESSAGE_H
#define MISTAKE_MESSAGE_H
#include "../message.h"

class mistake_message: public message{
public:
    mistake_message();
    mistake_message(std::string m);
    std::string getMessage() const;
    ~mistake_message() override;
    friend std::ostream& operator<<(std::ostream& out, const mistake_message& m);

private:
    std::string message_;
};


#endif //MISTAKE_MESSAGE_H
