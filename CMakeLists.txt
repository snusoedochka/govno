cmake_minimum_required(VERSION 3.21)
project(oop_lab1)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab2 main.cpp cell_object.cpp cell_object_view.cpp field_view.cpp field.cpp cells/cell_view.cpp cells/cell.cpp cells/cell_entrance.cpp cells/cell_exit.cpp actors/actor.cpp actors/player.cpp enemy_event/enemy_event.cpp enemy_event/enemies/acolyte.cpp enemy_event/enemies/skeleton.cpp actions/action_combat.cpp actions/action_shoot_ballistic.cpp actions/action_move.cpp actions/action.cpp item_event/item_event.cpp item_event/items/armor_item.cpp game_conditions/exit_condition.cpp game_conditions/player_death_condition.cpp logger/logger.cpp logger/console_logger.cpp logger/file_logger.cpp logger/logger_level.cpp logger/logger_pool.cpp logger/message.cpp logger/observer/observable.cpp logger/observer/observer.cpp logger/special_logger/event_logger.cpp logger/special_logger/game_logger.cpp logger/special_logger/mistake_logger.cpp logger/special_messages/event_message.cpp logger/special_messages/game_message.cpp logger/special_messages/mistake_message.cpp)
