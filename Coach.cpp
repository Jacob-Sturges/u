// Jacob Sturges
#include "Coach.h"
#include <iostream>

// Name: Coach
// Params: None
// Return: None (Constructor)
// Description: Initializes a Coach object with an empty feedback list.
Coach::Coach() {}

// Name: reviewGame
// Params: const Game& game
// Return: void
// Description: Analyzes a Game's move list and populates coaching feedback messages.
void Coach::reviewGame(const Game& game) {
    feedback.clear();
    const std::vector<Move> moves = game.getMoves();

    if (moves.empty()) {
        feedback.push_back("No moves available to review.");
        return;
    }

    if (detectEarlyQueen(moves)) {
        feedback.push_back("Early queen move detected");
    }

    if (detectRepeatedMoves(moves)) {
        feedback.push_back("Repeated piece movement");
    }

    if (feedback.empty()) {
        feedback.push_back("Balanced game");
    }
}

// Name: detectEarlyQueen
// Params: const std::vector<Move>& moves
// Return: bool
// Description: Returns true if a queen move ('Q') appears within the first 6 recorded moves.
bool Coach::detectEarlyQueen(const std::vector<Move>& moves) const {
    int limit = static_cast<int>(moves.size());
    if (limit > 6) {
        limit = 6;
    }
    for (int i = 0; i < limit; ++i) {
        const std::string& note = moves[i].getNotation();
        if (!note.empty() && note[0] == 'Q') {
            return true;
        }
    }
    return false;
}

// Name: detectRepeatedMoves
// Params: const std::vector<Move>& moves
// Return: bool
// Description: Returns true if the same algebraic notation string appears more than once.
bool Coach::detectRepeatedMoves(const std::vector<Move>& moves) const {
    for (size_t i = 0; i < moves.size(); ++i) {
        for (size_t j = i + 1; j < moves.size(); ++j) {
            if (moves[i].getNotation() == moves[j].getNotation()) {
                return true;
            }
        }
    }
    return false;
}

// Name: getFeedback
// Params: None
// Return: std::vector<std::string>
// Description: Returns the vector of coaching feedback strings.
std::vector<std::string> Coach::getFeedback() const {
    return feedback;
}

// Name: setFeedback
// Params: const std::vector<std::string>& items
// Return: void
// Description: Sets the feedback vector directly (useful when loading saved records).
void Coach::setFeedback(const std::vector<std::string>& items) {
    feedback = items;
}

// Name: displayFeedback
// Params: None
// Return: void
// Description: Prints all generated coaching feedback lines to standard output.
void Coach::displayFeedback() const {
    std::cout << "\n--- Coaching Feedback ---\n";
    if (feedback.empty()) {
        std::cout << "No feedback generated yet. Run game review first.\n";
        return;
    }
    for (const std::string& line : feedback) {
        std::cout << "- " << line << std::endl;
    }
}