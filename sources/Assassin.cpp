#include "Assassin.hpp"

void Assassin::coup(Player &p) {
    if(this->game->alone()) {
        throw invalid_argument("game only has 1 player");
    }
    if(this->game->turn() != this->name) {
        throw invalid_argument(this->name + " not your turn!");
    }
    if(p.get_status() != 0) {
        throw invalid_argument("illegal coup!");
    }
    if(this->money < 3) {
        throw invalid_argument("not enough coins");
    }
    if(this->money >= 7) {
        this->money -= 7;
        p.set_status(1);
        this->game->change_status(p.get_name(), 1);
        this->last_action = "COUP";
        this->affected = &p;
        this->game->next_turn();
    }
    else {
        this->money -= 3;
        p.set_status(1);
        this->game->change_status(p.get_name(), 1);
        this->last_action = "ASSASSINATE";
        this->affected = &p;
        this->game->next_turn();
    }
}
