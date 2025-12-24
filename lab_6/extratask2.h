#ifndef EXTRATASK2_H
#define EXTRATASK2_H

#include <vector>

enum class CellState {
    Empty,
    Cross,
    Nought
};

enum class GameState {
    InProgress,
    CrossWins,
    NoughtWins,
    Draw
};

class TicTacToe {
public:
    TicTacToe(); // Конструктор по умолчанию (3x3)
    TicTacToe(int size); // Конструктор с заданным размером поля

    int getSize() const;
    void setSize(int size);

    CellState getCellState(int row, int col) const;
    bool makeMove(int row, int col, CellState player);
    GameState getGameState() const;
    void printBoard() const;

    bool playerMove(CellState player); // Новый метод для запроса хода у игрока

private:
    int size;
    std::vector<std::vector<CellState>> board;
    int windowSize; // Размер отображаемой области
    int windowRow; // Координата верхнего левого угла отображаемой области (строка)
    int windowCol; // Координата верхнего левого угла отображаемой области (столбец)

    bool isValidInput(int input);
    bool isValidMove(int row, int col) const;
    GameState checkRows() const;
    GameState checkCols() const;
    GameState checkDiagonals() const;
};

#endif // EXTRATASK2_H
