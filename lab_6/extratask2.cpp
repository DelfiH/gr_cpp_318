#include "extratask2.h"
#include <iostream>

// Реализация конструктора по умолчанию
TicTacToe::TicTacToe() : TicTacToe(3) {}

// Реализация конструктора с заданным размером поля
TicTacToe::TicTacToe(int size) : size(0), board(0), windowSize(3), windowRow(0), windowCol(0) {
    setSize(size); // Используем сеттер для инициализации размера и создания поля
}

// Реализация метода getSize()
int TicTacToe::getSize() const {
    return size;
}

// Реализация метода setSize()
void TicTacToe::setSize(int size) {
    if (!isValidInput(size)) {
        std::cerr << "Ошибка: Некорректный размер игрового поля. Установлен размер по умолчанию (3x3)." << std::endl;
        this->size = 3;
    } else {
        this->size = size;
    }

    // Инициализация игрового поля
    board.resize(this->size, std::vector<CellState>(this->size, CellState::Empty));
}

// Реализация метода getCellState()
CellState TicTacToe::getCellState(int row, int col) const {
    if (row >= 0 && row < size && col >= 0 && col < size) {
        return board[row][col];
    } else {
        std::cerr << "Ошибка: Некорректные координаты ячейки." << std::endl;
        return CellState::Empty; // Возвращаем Empty в случае ошибки
    }
}

// Реализация метода makeMove()
bool TicTacToe::makeMove(int row, int col, CellState player) {
    if (!isValidMove(row, col)) {
        std::cout << "Недопустимый ход!" << std::endl;
        return false;
    }

    board[row][col] = player;
    return true;
}

// Реализация метода getGameState()
GameState TicTacToe::getGameState() const {
    // Проверяем строки, столбцы и диагонали на наличие выигрышных комбинаций
    GameState rowResult = checkRows();
    if (rowResult != GameState::InProgress) return rowResult;

    GameState colResult = checkCols();
    if (colResult != GameState::InProgress) return colResult;

    GameState diagonalResult = checkDiagonals();
    if (diagonalResult != GameState::InProgress) return diagonalResult;

    // Проверяем, есть ли еще пустые ячейки
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (board[i][j] == CellState::Empty) {
                return GameState::InProgress; // Игра продолжается
            }
        }
    }

    // Если пустых ячеек нет, то ничья
    return GameState::Draw;
}

// Реализация метода printBoard()
void TicTacToe::printBoard() const {
    std::cout << "  ";
    for (int j = 1; j <= size; ++j) {
        std::cout << j << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < size; ++i) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < size; ++j) {
            switch (board[i][j]) {
                case CellState::Empty:
                    std::cout << ". ";
                    break;
                case CellState::Cross:
                    std::cout << "X ";
                    break;
                case CellState::Nought:
                    std::cout << "O ";
                    break;
            }
        }
        std::cout << std::endl;
    }
}

// Реализация метода isValidInput()
bool TicTacToe::isValidInput(int input) {
    return input > 0; // Проверяем, что размер больше 0
}

// Реализация метода isValidMove()
bool TicTacToe::isValidMove(int row, int col) const {
    if (row < 0 || row >= size || col < 0 || col >= size) {
        return false; // Недопустимые координаты
    }
    return board[row][col] == CellState::Empty; // Проверяем, что ячейка свободна
}

// Реализация метода checkRows()
GameState TicTacToe::checkRows() const {
    for (int i = 0; i < size; ++i) {
        if (board[i][0] != CellState::Empty &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2]) {
            if (board[i][0] == CellState::Cross) return GameState::CrossWins;
            else return GameState::NoughtWins;
        }
    }
    return GameState::InProgress;
}

// Реализация метода checkCols()
GameState TicTacToe::checkCols() const {
    for (int j = 0; j < size; ++j) {
        if (board[0][j] != CellState::Empty &&
            board[0][j] == board[1][j] &&
            board[1][j] == board[2][j]) {
            if (board[0][j] == CellState::Cross) return GameState::CrossWins;
            else return GameState::NoughtWins;
        }
    }
    return GameState::InProgress;
}

// Реализация метода checkDiagonals()
GameState TicTacToe::checkDiagonals() const {
    if (board[0][0] != CellState::Empty &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2]) {
        if (board[0][0] == CellState::Cross) return GameState::CrossWins;
        else return GameState::NoughtWins;
    }

    if (board[0][2] != CellState::Empty &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0]) {
        if (board[0][2] == CellState::Cross) return GameState::CrossWins;
        else return GameState::NoughtWins;
    }

    return GameState::InProgress;
}

// Метод для запроса хода у игрока
bool TicTacToe::playerMove(CellState player) {
    int row, col;

    std::cout << "Игрок, введите строку (1-" << size << ") и столбец (1-" << size << "), разделенные пробелом: ";
    std::cin >> row >> col;

    // Преобразуем введенные координаты в координаты массива (индексы начинаются с 0)
    row--;
    col--;

    if (!isValidMove(row, col)) {
        std::cout << "Некорректный ход. Попробуйте еще раз." << std::endl;
        return false; // Ход не удался
    }

    makeMove(row, col, player);
    return true; // Ход удался
}
