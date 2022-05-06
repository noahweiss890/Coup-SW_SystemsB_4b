#include "Game.hpp"

namespace coup {

    const int max_players = 6;

    vector<string> Game::players() {
        vector<string> plrs;
        for(unsigned long i = 0; i < this->players_in_game.size(); i++) {
            if(this->players_status.at(i) == 0) {
                plrs.push_back(this->players_in_game.at(i));
            }
        }
        return plrs;
    }

    vector<int> Game::statuses() {
        vector<int> stts;
        for(unsigned long i = 0; i < this->players_status.size(); i++) {
            stts.push_back(this->players_status.at(i));
        }
        return stts;
    }

    string Game::turn() {
        if(this->players_in_game.empty()) {
            throw invalid_argument("no players in the game yet!");
        }
        return this->players_in_game.at(this->curr_turn);
    }

    string Game::winner() {
        if(!this->started) {
            throw invalid_argument("game didnt start yet!");
        }
        string win;
        for(unsigned long i = 0; i < this->players_in_game.size(); i++) {
            if(this->players_status.at(i) == 0) {
                if(!win.empty()) {
                    throw invalid_argument("game not over yet!");
                }
                win = this->players_in_game.at(i);
            }
        }
        return win;
    }

    bool Game::alone() {
        int alive = 0;
        for(unsigned long i = 0; i < this->players_in_game.size(); i++) {
            if(this->players_status.at(i) == 0) {
                alive++;
            }
        }
        return alive == 1;
    }

    void Game::add_player(string const &name) {
        if(started || this->players_in_game.size() == max_players) {
            throw invalid_argument("game already started, cant add more players!");
        }
        this->players_in_game.push_back(name);
        this->players_status.push_back(0);
    }

    void Game::next_turn() {
        if(!this->started) {
            this->started = true;
        }
        this->last_turn = this->curr_turn;
        this->curr_turn = (this->curr_turn + 1) % this->players_in_game.size();
        while(this->players_status.at(this->curr_turn) != 0) {
            this->curr_turn = (this->curr_turn + 1) % this->players_in_game.size();
        }
    }

    void Game::change_status(string const &name, int status) {
        for(unsigned long i = 0; i < this->players_in_game.size(); i++) {
            if(this->players_in_game.at(i) == name) {
                this->players_status.at(i) = status;
                return;
            }
        }
        throw invalid_argument("player not in game!");
    }

    void Game::brought_back() {
        this->curr_turn = this->last_turn;
        this->next_turn();
    }
}
