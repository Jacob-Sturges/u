// Jacob Sturges
// Summary of Menu Class: Stores the user's current menu selection and displays/processes menu options.

#ifndef MENU_H
#define MENU_H

class Menu {
private:
    int choice;

public:
    Menu();

    void setChoice(int option);
    int getChoice() const;

    void displayMenu() const;
    bool processSelection(int option) const;
};

#endif