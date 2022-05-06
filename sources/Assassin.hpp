#include <iostream>
#include "Player.hpp"

using namespace coup;
using namespace std;

class Assassin : public Player {
    public:
        Assassin(Game &g, string name) : Player(g, name, "Assassin") {
            
        }
        void coup(Player &p);
};
