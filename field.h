#ifndef FIELD_H
#define FIELD_H

#include <cstdlib>
#include "logger/observer/observable.h"
//#include "logger/console_logger.h"
//#include "logger/file_logger.h"
//#include "logger/logger_pool.h"
#include "logger/special_messages/mistake_message.h"
//#include "logger/special_logger/mistake_logger.h"
#include "cells/cell_entrance.h"

class field
{
	public:

	field(const field& other);
	field(field&& other);
	~field();
	field& operator=(const field& other);
	field& operator=(field&& other);

	field(size_t w, size_t h);

	// Basic manipulation methods

	size_t get_w() const;
	size_t get_h() const;
	void set_size(size_t w, size_t h);

	cell& get_cell(size_t x, size_t y) const;
	void set_cell(size_t x, size_t y, cell* c);

	// Generation

	cell_entrance* generate_entrance_exit(size_t min_dist = 3);
	// Gamesim

	void tickActors();

    //void addObserver(observer * o) override;
    //void notify(message * message) override;


	private:

	cell** cells;
	size_t cells_w, cells_h;
    //observer* obs;
};

#endif
