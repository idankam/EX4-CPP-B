#pragma once
#include "Player.hpp"

namespace coup {
    class Assassin : public Player {
    public:
        Assassin(Game &game,const std::string& playerName);
        std::string role() const override;
        virtual void coup(Player& player) override;
    };
}
