# Jacob Sturges
## Chess Game Reviewer
## A C++ console application that lets players record chess moves in algebraic notation, review games for basic coaching patterns like early queen moves and repeated piece movement, and save or load games in CSV format.

---

## checkpoint-01: Initial project structure / setup

1. What challenges did you encounter?
Setting up the multi-file project workspace and checking `.vscode/tasks.json` so VSCode compiles all `.cpp` files together required verifying the build configuration.

2. What design decisions or changes did you make?
I organized the project folder around my Phase II design by creating empty header and source files for `Move`, `Game`, `Coach`, `FileManager`, and `Menu`, along with `games.csv` for data persistence.
---

## checkpoint-02: class declaration

1. What challenges did you encounter?
Designing clean class interfaces and deciding which helper methods belonged inside each class versus standalone functions required balancing encapsulation with straightforward data access between classes.

2. What design decisions or changes did you make?
I added include guards and header summary comments to every `.h` file, kept data members private (`moveNumber`, `notation`, `whitePlayer`, `blackPlayer`, `result`, `moves`, `feedback`, `fileName`, `choice`), and declared constructors, getters, setters, and core methods aligned with the Phase II UML diagrams.