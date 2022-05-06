#include <iostream>
#include "Player.hpp"

using namespace coup;
using namespace std;

class Captain : public Player {
    public:
        Captain(Game &g, string name) : Player(g, name, "Captain") {
            
        }
        void steal(Player &from);
        void block(Player &p);
};
