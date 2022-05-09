#pragma once
#include "Player.hpp"

namespace coup {

    class Captain : public Player {
    public:
        Captain(Game &game, const string& playerName);
        string role() const override;
        void steal(Player &player);
        void block(Player &player);
    };
}
