#pragma once
#include "Player.hpp"

namespace coup {

    class Ambassador : public Player {
    public:
        Ambassador(Game &game, const string& playerName);
        std::string role() const override;
        void transfer(const Player &player1, const Player &player2);
        void block(const Player &player);
    };
}
