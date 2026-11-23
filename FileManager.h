// Jacob Sturges
// Summary of FileManager Class: Handles saving and loading chess game records in CSV format.

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>
#include "Game.h"
#include "Coach.h"

class FileManager {
private:
    std::string fileName;

public:
    FileManager();
    explicit FileManager(const std::string& file);

    void setFileName(const std::string& file);
    std::string getFileName() const;

    bool saveGame(const Game& game, const Coach& coach) const;
    bool loadGame(Game& game, Coach& coach, int recordIndex = -1) const;
};

#endif