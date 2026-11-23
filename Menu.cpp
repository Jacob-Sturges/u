// Jacob Sturges
#include "Menu.h"
#include <iostream>

// Name: Menu
// Params: None
// Return: None (Constructor)
// Description: Initializes a Menu object with default choice 0.
Menu::Menu() : choice(0) {}

// Name: setChoice
// Params: int option
// Return: void
// Description: Sets the currently selected menu option.
void Menu::setChoice(int option) {
    choice = option;
}

// Name: getChoice
// Params: None
// Return: int
// Description: Returns the currently stored menu option.
int Menu::getChoice() const {
    return choice;
}

// Name: displayMenu
// Params: None
// Return: void
// Description: Prints the main Chess Game Reviewer menu options to standard output.
void Menu::displayMenu() const {
    std::cout << "\n===========================\n";
    std::cout << "    CHESS GAME REVIEWER\n";
    std::cout << "===========================\n";
    std::cout << "1. Start New Game\n";
    std::cout << "2. Enter Moves\n";
    std::cout << "3. View Moves\n";
    std::cout << "4. Review Game\n";
    std::cout << "5. Save Game\n";
    std::cout << "6. Load Game\n";
    std::cout << "7. Exit\n";
}

// Name: processSelection
// Params: int option
// Return: bool
// Description: Returns false if option 7 (Exit) was selected, otherwise returns true to continue.
bool Menu::processSelection(int option) const {
    if (option == 7) {
        std::cout << "Exiting Chess Game Reviewer. Goodbye!\n";
        return false;
    }
    return true;
}