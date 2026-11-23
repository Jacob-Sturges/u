// Jacob Sturges
// Summary of Move Class: Represents a single chess move with its move number and algebraic notation.

#ifndef MOVE_H
#define MOVE_H

#include <string>

class Move {
private:
    int moveNumber;
    std::string notation;

public:
    Move();
    Move(int moveNum, const std::string& moveNotation);

    void setMove(int moveNum, const std::string& moveNotation);
    std::string getMove() const;
    int getMoveNumber() const;
    std::string getNotation() const;
    void displayMove() const;
};

#endif