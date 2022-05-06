#include <iostream>
#include "Player.hpp"

using namespace coup;
using namespace std;

class Ambassador : public Player {
    public:
        Ambassador(Game &g, string name) : Player(g, name, "Ambassador") {

        }
        void transfer(Player &from, Player &to);
        void block(Player &p);
};
