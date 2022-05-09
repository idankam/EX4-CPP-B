#pragma once
#include "Player.hpp"

namespace coup {

    class Contessa : public Player {
        
    public:
        Contessa(Game &Game, const string &playerName);
        string role() const override;
        void block(Player &other_player);        
    };
}
