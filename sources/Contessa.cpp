#include "Contessa.hpp"

namespace coup {
    Contessa::Contessa(Game &game, const string& playerName) : Player{game, playerName} {}
    string Contessa::role() const { return "Contessa"; }
    void Contessa::block(Player &Player){}
}