// Jacob Sturges
#include "Move.h"
#include <iostream>

// Name: Move
// Params: None
// Return: None (Constructor)
// Description: Initializes a Move object with default move number 0 and empty notation.
Move::Move() : moveNumber(0), notation("") {}

// Name: Move
// Params: int moveNum, const std::string& moveNotation
// Return: None (Constructor)
// Description: Initializes a Move object with a specified move number and algebraic notation.
Move::Move(int moveNum, const std::string& moveNotation)
    : moveNumber(moveNum), notation(moveNotation) {}

// Name: setMove
// Params: int moveNum, const std::string& moveNotation
// Return: void
// Description: Updates both the move number and algebraic notation for this move.
void Move::setMove(int moveNum, const std::string& moveNotation) {
    moveNumber = moveNum;
    notation = moveNotation;
}

// Name: getMove
// Params: None
// Return: std::string
// Description: Returns a formatted string representation of the move number and notation.
std::string Move::getMove() const {
    return std::to_string(moveNumber) + ". " + notation;
}

// Name: getMoveNumber
// Params: None
// Return: int
// Description: Returns the stored move number.
int Move::getMoveNumber() const {
    return moveNumber;
}

// Name: getNotation
// Params: None
// Return: std::string
// Description: Returns the stored algebraic move notation.
std::string Move::getNotation() const {
    return notation;
}

// Name: displayMove
// Params: None
// Return: void
// Description: Prints the move number and algebraic notation to standard output.
void Move::displayMove() const {
    std::cout << moveNumber << ". " << notation << std::endl;
}