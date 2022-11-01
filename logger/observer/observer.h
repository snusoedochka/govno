#ifndef OBSERVER_H
#define OBSERVER_H

#include <functional>
#include <iostream>
#include <vector>

#include "../logger.h"
#include "../message.h"

class observer
{

public:

    virtual void update(message* message) = 0;

};

#endif