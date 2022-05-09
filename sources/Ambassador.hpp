#pragma once
#include "Player.hpp"

namespace coup {

    class Ambassador : public Player {
    public:
        Ambassador(Game &game, const string& playerName);
        std::string role() const override;
        void transfer(Player &player1, Player &player2);
        void block(Player &player);
    };
}
