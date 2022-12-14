#include "my_game.h"

#include <iostream>

#include <string>

//#include "enemy_event/enemies/skeleton.h"
//#include "enemy_event/enemies/acolyte.h"
#include "item_event/items/armor_item.h"

//#include "logger/console_logger.h"
//#include "logger/file_logger.h"

//#include "logger/logger_pool.h"

static void clear_tscreen()
{
    std::cout << "\n";
}
std::vector<actor_spawner_func> game::enemy_spawn_funcs;

game::game(game_condition& win_cond, game_condition& lose_cond) : win_cond(win_cond), lose_cond(lose_cond)
{}

void game::init()
{
    logger_pool* lp = new logger_pool();
    addObserver(lp);
    lp->config();

    int size;
    std::cout << "Enter size:";
    std::cin >> size;
    //field f;
    if (size > 1){
        mainfield = new field(size, size);
    }
    else{
        mainfield = new field(15, 15);;
    }

    mainfield_view = new field_view(*mainfield);

    cell_entrance* ce = mainfield->generate_entrance_exit(3);

    mainplr = new player();
    {
        mainplr->setMaxHealth(30);
        mainplr->setHealth(30);
        mainplr->setTeamID(10);
        ce->set_object(mainplr);
        mainplr->addItemToInventory(new armor_item(2, 0.2));
    }

    {
        enemy_spawn_funcs.emplace_back([](const cell& pc){return new acolyte();});
        actor_spawner<enemy_spawn_funcs> enemy_spawner;
        const std::vector<actor*>& enemies_spawned = enemy_spawner.doSpawn(*mainfield);
        actors_spawned.insert(actors_spawned.end(), enemies_spawned.begin(), enemies_spawned.end());
    }
    //logger_pool* lp = new logger_pool();
    //mainfield->addObserver(lp);


}


void game::run()
{

    clear_tscreen();
    //mainfield_view->display();
    getc(stdin);
    while(1){
        clear_tscreen();
        mainfield->tickActors();

        if(win_cond.isMet()){
            //logger::message(LEVEL_GAME, "VICTORY!");
            break;
        }
        if(lose_cond.isMet()){
            //logger::message(LEVEL_GAME, "You LOOSE!");
            break;
        }
        cell* cur = &mainplr->getParentCell();

        //std::stringstream ss;
        //ss << mainplr->getName() << " take place " << cur->get_x() << " longitude and  " << cur->get_y()
        //   << " width";
//        logger::message(LEVEL_EVENT, ss.str());
        std::string mv = mainplr->getName() + " take place " + std::to_string(cur->get_x()) + " longitude and  "+ std::to_string(cur->get_y()) + " width\n";
        //mv.append(mainplr->getName() << " take place ")
        notify(new event_message(mv));
        mainfield_view->display();

        std::cout << '\n' << "Where r u ganna be: ";
        switch(getchar()){
            case '8':
                cur->set_object(nullptr);
                cur = &cur->get_parent_field().get_cell(cur->get_x()-1, cur->get_y());
                cur->set_object(mainplr);

                //mainfield_view->display();
                break;
            case '2':
                cur->set_object(nullptr);
                cur = &cur->get_parent_field().get_cell(cur->get_x() +1 , cur->get_y());
                cur->set_object(mainplr);
                break;
            case '4':
                cur->set_object(nullptr);
                cur = &cur->get_parent_field().get_cell(cur->get_x(), cur->get_y()-1);
                cur->set_object(mainplr);
                break;
            case '6':
                cur->set_object(nullptr);
                cur = &cur->get_parent_field().get_cell(cur->get_x()  , cur->get_y()+1);
                cur->set_object(mainplr);
                break;
            default:
                //logger::message(LEVEL_MISTAKE, "You can't move");
                notify(new event_message("You can't move\n"));
                break;
        }
        getc(stdin);
    }
    //delete lp;
}

game::~game()
{
    delete mainplr;
    for(size_t i = 0; i < actors_spawned.size(); ++i)
        delete actors_spawned[i];
}


// public getters
const player* game::getMainPlayer() { return mainplr; }

void game::addObserver(observer *o) {
    ob = o;
}

void game::notify(message *message) {
    ob->update(message);
}

//?????????????? ?????????????????? ?????????????????? - ?????????????????? ????
//?????????????????? ???????????? ???????? ???????????????? ????????