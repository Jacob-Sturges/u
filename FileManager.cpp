// Jacob Sturges
#include "FileManager.h"
#include <fstream>
#include <iostream>
#include <sstream>

// Name: FileManager
// Params: None
// Return: None (Constructor)
// Description: Initializes a FileManager using the default data file name games.csv.
FileManager::FileManager() : fileName("games.csv") {}

// Name: FileManager
// Params: const std::string& file
// Return: None (Constructor)
// Description: Initializes a FileManager with a custom target CSV file name.
FileManager::FileManager(const std::string& file) : fileName(file) {}

// Name: setFileName
// Params: const std::string& file
// Return: void
// Description: Updates the CSV file path used for reading and writing game records.
void FileManager::setFileName(const std::string& file) {
    fileName = file;
}

// Name: getFileName
// Params: None
// Return: std::string
// Description: Returns the configured CSV file name.
std::string FileManager::getFileName() const {
    return fileName;
}

// Name: saveGame
// Params: const Game& game, const Coach& coach
// Return: bool
// Description: Appends a game record (players, result, moves, and feedback) to the CSV file.
bool FileManager::saveGame(const Game& game, const Coach& coach) const {
    std::ifstream checkIn(fileName);
    bool needsHeader = !checkIn.good();
    if (checkIn.is_open()) {
        checkIn.peek();
        if (checkIn.eof()) {
            needsHeader = true;
        }
        checkIn.close();
    }

    std::ofstream outFile(fileName, std::ios::app);
    if (!outFile.is_open()) {
        std::cout << "Error: Unable to open '" << fileName << "' for writing.\n";
        return false;
    }

    if (needsHeader) {
        outFile << "WhitePlayer,BlackPlayer,Result,Moves,Feedback\n";
    }

    std::string movesStr;
    const std::vector<Move> moves = game.getMoves();
    for (size_t i = 0; i < moves.size(); ++i) {
        if (i > 0) {
            movesStr += " ";
        }
        movesStr += moves[i].getNotation();
    }

    std::string feedbackStr;
    const std::vector<std::string> fb = coach.getFeedback();
    for (size_t i = 0; i < fb.size(); ++i) {
        if (i > 0) {
            feedbackStr += "; ";
        }
        feedbackStr += fb[i];
    }
    if (feedbackStr.empty()) {
        feedbackStr = "No review recorded";
    }

    outFile << game.getWhitePlayer() << ","
            << game.getBlackPlayer() << ","
            << game.getResult() << ","
            << movesStr << ","
            << feedbackStr << "\n";

    outFile.close();
    return true;
}

// Name: loadGame
// Params: Game& game, Coach& coach, int recordIndex
// Return: bool
// Description: Loads a saved game record from the CSV file into Game and Coach objects.
bool FileManager::loadGame(Game& game, Coach& coach, int recordIndex) const {
    std::ifstream inFile(fileName);
    if (!inFile.is_open()) {
        std::cout << "Error: Could not find or open '" << fileName << "'.\n";
        return false;
    }

    std::vector<std::string> records;
    std::string line;
    bool isFirstLine = true;

    while (std::getline(inFile, line)) {
        if (line.empty()) {
            continue;
        }
        if (isFirstLine) {
            isFirstLine = false;
            if (line.rfind("WhitePlayer,", 0) == 0) {
                continue;
            }
        }
        records.push_back(line);
    }
    inFile.close();

    if (records.empty()) {
        std::cout << "Notice: '" << fileName << "' is empty or has no saved games.\n";
        return false;
    }

    if (recordIndex < 0) {
        std::cout << "\nSaved Games in " << fileName << ":\n";
        for (size_t i = 0; i < records.size(); ++i) {
            std::stringstream ss(records[i]);
            std::string w, b, r;
            std::getline(ss, w, ',');
            std::getline(ss, b, ',');
            std::getline(ss, r, ',');
            std::cout << (i + 1) << ". " << w << " vs. " << b << " (" << r << ")\n";
        }
        return true;
    }

    if (recordIndex < 1 || recordIndex > static_cast<int>(records.size())) {
        std::cout << "Invalid record selection.\n";
        return false;
    }

    std::stringstream ss(records[static_cast<size_t>(recordIndex - 1)]);
    std::string white, black, result, movesPart, feedbackPart;
    std::getline(ss, white, ',');
    std::getline(ss, black, ',');
    std::getline(ss, result, ',');
    std::getline(ss, movesPart, ',');
    std::getline(ss, feedbackPart);

    game.setPlayers(white, black);
    game.setResult(result);
    game.clearMoves();

    std::stringstream moveStream(movesPart);
    std::string singleMove;
    int moveNum = 1;
    while (moveStream >> singleMove) {
        game.addMove(Move(moveNum++, singleMove));
    }

    std::vector<std::string> loadedFeedback;
    if (!feedbackPart.empty()) {
        loadedFeedback.push_back(feedbackPart);
    }
    coach.setFeedback(loadedFeedback);

    return true;
}