// Jacob Sturges
// Summary of Coach Class: Analyzes a Game's moves for simple patterns and stores coaching feedback.

#ifndef COACH_H
#define COACH_H

#include <string>
#include <vector>
#include "Game.h"

class Coach {
private:
    std::vector<std::string> feedback;

public:
    Coach();

    void reviewGame(const Game& game);
    bool detectEarlyQueen(const std::vector<Move>& moves) const;
    bool detectRepeatedMoves(const std::vector<Move>& moves) const;
    std::vector<std::string> getFeedback() const;
    void setFeedback(const std::vector<std::string>& items);
    void displayFeedback() const;
};

#endif