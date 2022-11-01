#ifndef ACTION_MOVE_H
#define ACTION_MOVE_H

#include "action.h"

#include <cstddef>

#include "../logger/logger.h"

class action_move : public action
{
private:
    //Level_Event* logging_level;

public:

	action_move(double ap_per_cell);
    const std::string getName();


	size_t getAPCost(actor* active, actor* passive, cell* c);
	bool canExecute(size_t ap, actor* active, actor* passive, cell* c);

    void execute(size_t& ap, actor* active, actor* passive, cell* c);

protected:

	double ap_per_cell;
};

#endif
