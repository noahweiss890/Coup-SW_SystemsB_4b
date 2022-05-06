#include "Duke.hpp"

void Duke::tax() {
    if(this->game->alone()) {
        throw invalid_argument("game only has 1 player");
    }
    if(this->game->turn() != this->name) {
        throw invalid_argument(this->name + " not your turn!");
    }
    this->must_coup();
    this->set_money(3);
    this->last_action = "TAX";
    this->game->next_turn();
}

void Duke::block(Player &p) {
    if(p.get_status() != 0 || this->game->turn() == p.get_name() || p.get_last_action() != "FOREIGN AID") {
        throw invalid_argument("illegal block!");
    }
    p.set_money(-2);
}