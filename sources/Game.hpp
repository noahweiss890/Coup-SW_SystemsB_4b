#pragma once

#include <iostream>
#include <vector>
#include <string>


using namespace std;

namespace coup {
    class Game {
        vector<string> players_in_game;
        vector<int> players_status;
        unsigned long curr_turn;
        unsigned long last_turn;
        bool started;
        public:
            Game() {
                curr_turn = 0;
                started = false;
            }
            vector<string> players();
            vector<int> statuses();
            string turn();
            string winner();
            bool alone();
            void add_player(string const &name);
            void next_turn();
            void change_status(string const &name, int status);
            void brought_back();
    };
}
