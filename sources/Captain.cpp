#include "Captain.hpp"

void Captain::steal(Player &from) {
    if(this->game->alone()) {
        throw invalid_argument("game only has 1 player");
    }
    if(this->game->turn() != this->name) {
        throw invalid_argument(this->name + " not your turn!");
    }
    this->must_coup();
    if(from.get_status() != 0) {
        throw invalid_argument("illegal steal!");
    }
    int steal_amount;
    if(from.coins() >=2) {
        steal_amount = 2;
    }
    else if(from.coins() == 1) {
        steal_amount = 1;
    }
    else {
        steal_amount = 0;
    }
    this->set_money(steal_amount);
    from.set_money(-steal_amount);
    this->affected = &from;
    this->last_action = "STEAL " + to_string(steal_amount);
    this->game->next_turn();
}

void Captain::block(Player &p) {
    if(p.get_status() != 0 || this->game->turn() == p.get_name() || p.role() != "Captain" || p.get_last_action().substr(0, 5) != "STEAL") {
        throw invalid_argument("invalid block!");
    }
    p.set_money(-stoi(p.get_last_action().substr(p.get_last_action().size()-1, 1)));
    p.get_affected()->set_money(stoi(p.get_last_action().substr(p.get_last_action().size()-1, 1)));
}
