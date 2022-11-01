#include "my_game.h"
#include "my_game.cpp"
//#include "logger/observer/observable.h"
#include "game_conditions/exit_condition.h"
#include "game_conditions/player_death_condition.h"

int main()
{
    exit_condition win_cond;
    player_death_condition lose_cond;

    game maingame(win_cond, lose_cond);
    maingame.init();
    win_cond.setPlayer(maingame.getMainPlayer());
    lose_cond.setPlayer(maingame.getMainPlayer());
    maingame.run();
/*
    std::ofstream file;
    file.open("C:/Users/romas/Desktop/new_2-master/text.txt");
    file << "zhopa\n";
    file << "kakashka";
    file.close();*/
}