// Jacob Sturges
#include "Game.h"
#include <iostream>

// Name: Game
// Params: None
// Return: None (Constructor)
// Description: Initializes an empty Game object with default players and result.
Game::Game() : whitePlayer(""), blackPlayer(""), result("1/2-1/2") {}

// Name: Game
// Params: const std::string& white, const std::string& black, const std::string& gameResult
// Return: None (Constructor)
// Description: Initializes a Game object with white/black player names and game result.
Game::Game(const std::string& white, const std::string& black, const std::string& gameResult)
    : whitePlayer(white), blackPlayer(black), result(gameResult) {}

// Name: setPlayers
// Params: const std::string& white, const std::string& black
// Return: void
// Description: Sets the names of the white and black players.
void Game::setPlayers(const std::string& white, const std::string& black) {
    whitePlayer = white;
    blackPlayer = black;
}

// Name: setResult
// Params: const std::string& gameResult
// Return: void
// Description: Sets the outcome string of the game (such as 1-0, 0-1, or 1/2-1/2).
void Game::setResult(const std::string& gameResult) {
    result = gameResult;
}

// Name: getWhitePlayer
// Params: None
// Return: std::string
// Description: Returns the name of the player with the white pieces.
std::string Game::getWhitePlayer() const {
    return whitePlayer;
}

// Name: getBlackPlayer
// Params: None
// Return: std::string
// Description: Returns the name of the player with the black pieces.
std::string Game::getBlackPlayer() const {
    return blackPlayer;
}

// Name: getResult
// Params: None
// Return: std::string
// Description: Returns the recorded result of the game.
std::string Game::getResult() const {
    return result;
}

// Name: addMove
// Params: const Move& move
// Return: void
// Description: Appends a Move object to the game's move vector.
void Game::addMove(const Move& move) {
    moves.push_back(move);
}

// Name: getMoves
// Params: None
// Return: std::vector<Move>
// Description: Returns a copy of all recorded Move objects in the game.
std::vector<Move> Game::getMoves() const {
    return moves;
}

// Name: clearMoves
// Params: None
// Return: void
// Description: Removes all moves currently stored in the game.
void Game::clearMoves() {
    moves.clear();
}

// Name: displayMoves
// Params: None
// Return: void
// Description: Displays game header details and every recorded move in order.
void Game::displayMoves() const {
    std::cout << "\n--- Game Moves (" << whitePlayer << " vs. " << blackPlayer
              << " | Result: " << result << ") ---\n";
    if (moves.empty()) {
        std::cout << "No moves recorded yet.\n";
        return;
    }
    for (const Move& m : moves) {
        m.displayMove();
    }
}