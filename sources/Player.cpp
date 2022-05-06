#include "Player.hpp"

const int coup_price = 7;
const int max_coins = 10;

void Player::income() {
    if(this->game->alone()) {
        throw invalid_argument("game only has 1 player");
    }
    if(this->game->turn() != this->name) {
        throw invalid_argument(this->get_name() + " not your turn!");
    }
    this->must_coup();
    this->money++;
    this->last_action = "INCOME";
    this->affected = NULL;
    this->game->next_turn();
}

void Player::foreign_aid() {
    if(this->game->alone()) {
        throw invalid_argument("game only has 1 player");
    }
    if(this->game->turn() != this->name) {
        throw invalid_argument(this->get_name() + " not your turn!");
    }
    this->must_coup();
    this->money += 2;
    this->last_action = "FOREIGN AID";
    this->affected = NULL;
    this->game->next_turn();
}

void Player::coup(Player &p) {
    if(this->game->alone()) {
        throw invalid_argument("game only has 1 player");
    }
    if(this->game->turn() != this->name) {
        throw invalid_argument(this->get_name() + " not your turn!");
    }
    if(p.status != 0) {
        throw invalid_argument("illegal coup!");
    }
    if(this->money < coup_price) {
        throw invalid_argument("not enough coins");
    }
    this->money -= coup_price;
    p.set_status(1);
    this->game->change_status(p.name, 1);
    this->last_action = "COUP";
    this->affected = NULL;
    this->game->next_turn();
}

int Player::coins() const {
    return this->money;
}

string Player::get_name() {
    return this->name;
}

int Player::get_status() const {
    return this->status;
}

void Player::set_status(int s) {
    this->status = s;
} 

string Player::get_last_action() {
    return this->last_action;
}

void Player::set_money(int m) {
    this->money += m;
}

void Player::must_coup() const {
    if(this->money >= max_coins) {
        throw invalid_argument("player has 10+ coins and must coup!");
    }
}

Player* Player::get_affected() {
    return this->affected;
}

string Player::role() {
    return this->card;
}
