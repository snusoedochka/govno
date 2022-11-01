#ifndef GAME_H
#define GAME_H

#include "enemy_event/enemies/acolyte.h"

#include "actors/actor_spawner.h"
#include "actors/actor_spawner.cpp"
#include "game_conditions/game_condition.h"

#include "actors/player.h"

#include "field.h"
#include "field_view.h"

//#include "logger/ostream_wrapper.h"
//#include "logger/observer/observer_actor.h"
#include "logger/observer/observable.h"
#include "logger/special_messages/event_message.h"
#include "logger/special_messages/mistake_message.h"
#include "logger/special_messages/game_message.h"
#include "logger/special_logger/game_logger.h"
#include "logger/special_logger/event_logger.h"
#include "logger/special_logger/mistake_logger.h"
#include "logger/logger_pool.h"
#include "logger/console_logger.h"
#include "logger/file_logger.h"

class game: observable
{
private:
    //logger_pool * lp;
    field* mainfield;
    field_view* mainfield_view;

    player* mainplr = nullptr;
    static std::vector<actor_spawner_func> enemy_spawn_funcs;
    std::vector<actor*> actors_spawned;

    game_condition& win_cond;
    game_condition& lose_cond;

    observer* obs;

public:

    // game management
    game(game_condition& win_cond, game_condition& lose_cond);
    ~game();

    void init();
    void run();

    // public getters
    const player* getMainPlayer();

    void addObserver(observer * o) override;
    void notify(message * message) override;
};

#endif