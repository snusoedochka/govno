#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "observer.h"

class observable
{

public:

    virtual void addObserver(observer * o) = 0;
    virtual void notify(message * message) = 0;
    virtual ~observable() = 0;

protected:

    observer* ob = nullptr;

};

#endif