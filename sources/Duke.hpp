#pragma once
#include "Player.hpp"

namespace coup {
    class Duke : public Player {

    public:
        Duke(Game &game, const string &playerName);
        void block(Player &player);
        void tax();
        string role() const override;
    };
}
