#include "exception"
#include "vector"
#include "Game.hpp"

namespace coup {

    vector<string> Game::players() {
        return this->_players;
    }

    string Game::turn() {
        return this->_players[this->playerTurn];
    }

    void Game::nextPlayerTurn() {
        if (this->_players.size() < 2) {
            throw invalid_argument("No enough players.");
        }
        this->playerTurn++;
        this->playerTurn = this->playerTurn % this->_players.size();
    }

    void Game::addPlayer(const string &playerName) {
        if(this->_players.size() == 6){
            throw invalid_argument("Max players, can't add more.");
        }
        this->_players.push_back(playerName);
    }

    string Game::winner() {
        if (this->_players.size() >= 2) {
            throw invalid_argument("No winner yet.");
        }
        return this->_players[0];
    }

}
