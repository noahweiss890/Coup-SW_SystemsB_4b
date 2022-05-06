#include "Contessa.hpp"


void Contessa::block(Player &p) {
    if(p.get_status() != 0 || this->game->turn() == p.get_name() || p.role() != "Assassin" || p.get_last_action() != "ASSASSINATE" || p.get_affected()->get_status() == 0) {
        throw invalid_argument("illegal block");
    }
    p.get_affected()->set_status(0);
    this->game->change_status(p.get_affected()->get_name(), 0);
    this->game->brought_back();
}
