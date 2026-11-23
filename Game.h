// Jacob Sturges
// Summary of Game Class: Stores white/black player names, game result, and a list of Move objects.

#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include "Move.h"

class Game {
private:
    std::string whitePlayer;
    std::string blackPlayer;
    std::string result;
    std::vector<Move> moves;

public:
    Game();
    Game(const std::string& white, const std::string& black, const std::string& gameResult);

    void setPlayers(const std::string& white, const std::string& black);
    void setResult(const std::string& gameResult);
    std::string getWhitePlayer() const;
    std::string getBlackPlayer() const;
    std::string getResult() const;

    void addMove(const Move& move);
    std::vector<Move> getMoves() const;
    void clearMoves();
    void displayMoves() const;
};

#endif