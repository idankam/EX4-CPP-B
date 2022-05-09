#include <exception>
#include <algorithm>
#include "Game.hpp"

namespace coup {

    vector<string> Game::players() {
        vector<string> names;
        for (size_t i = 0; i < this->_players_ID.size(); i++){
            Player *p = this->getPlayerByID(_players_ID[i]);
            names.push_back(p->getName());
        }

        return names;
    }

    string Game::turn() {
        int id = _players_ID[playerTurn];
        size_t i=0;
        for(; i<_players_alive.size(); i++){
            if (_players_alive[i]->getID() == id){
                break;
            }
        }
        Player *p = _players_alive[i];
        // coup::Player* p = this->_players_alive[this->playerTurn];
        return p->getName();
    }

    void Game::nextPlayerTurn() {
        // if (this->_players_ID.size() < 2) {
        //     throw invalid_argument("No enough players.");
        // }
        this->playerTurn++;
        this->playerTurn = this->playerTurn % this->_players_ID.size();
    }

    void Game::addPlayerName(const string& playerName, int playerID){
        if(this->_players.size() == coup::HIGH_BORDER_ASSASSIN){
            throw invalid_argument("Max players, can't add more.");
        }
        this->_players.push_back(playerName);
        this->_players_ID.push_back(playerID);
    }

    void Game::addPlayer(Player* player) {
        if(this->_players_alive.size() == coup::HIGH_BORDER_ASSASSIN){
            throw invalid_argument("Max players, can't add more.");
        }
        this->_players_alive.push_back(player);
    }

    void Game::removePlayer(Player* player) {
        _players_ID.erase(std::remove(_players_ID.begin(), _players_ID.end(), player->getID()), _players_ID.end());
    }

    string Game::winner() {
        if (this->_players_ID.size() >= 2) {
            throw invalid_argument("No winner yet.");
        }
        if (!this->isGameStarted()){
            throw invalid_argument("game didnt started yet.");
        }

        size_t i=0;
        for(; i<_players_alive.size(); i++){
            if (_players_alive[i]->getID() == _players_ID[0]){
                break;
            }
        }
        Player *p = _players_alive[i];
        return p->getName();
    }

    void Game::backToGame(int id){
        long i = 0;
        for (; i < this->_players_ID.size(); i++)
        {
            if(_players_ID[(size_t) i]>id){
                break;
            }
        }
        auto itPos = _players_ID.begin() + i;
        _players_ID.insert(itPos, id);
    }

    Player* Game::getPlayerByID(int id){
        size_t i = 0;
        for (; i < this->_players_alive.size(); i++){
            if(_players_alive[i]->getID() == id){
                break;
            }
        }
        return _players_alive[i];
    }
}
