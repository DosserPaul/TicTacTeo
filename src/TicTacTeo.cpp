//
// Created by kiwi on 20/11/22.
//

#include "TicTacTeo.hpp"
#include "IA/MiniMax.hpp"

namespace TicTacTeo {

    TicTacTeo::TicTacTeo() {
        initBoard();
        displayBoard();
        gameLoop();
    }

    void TicTacTeo::initBoard() {
        _board = std::vector<std::vector<int>>(3, std::vector<int>(3, 0));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                _board[i][j] = Player::NONE;
            }
        }

        _board[0][0] = Player::IA_2;
    }

    void TicTacTeo::displayBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
//                std::cout << _board[i][j] << " ";
                if (_board[i][j] == Player::IA_1)
                    std::cout << "X ";
                else if (_board[i][j] == Player::IA_2)
                    std::cout << "O ";
                else
                    std::cout << ". ";
            }
            std::cout << std::endl;
        }
    }

    std::string TicTacTeo::checkWin() {
        std::string winner;

        // Check rows
        for (std::size_t i = 0; i < 3; ++i) {
            if (_board[i][0] == _board[i][1] && _board[i][1] == _board[i][2]) {
                if (_board[i][0] == Player::IA_1) {
                    winner = "IA 1";
                } else if (_board[i][0] == Player::IA_2) {
                    winner = "IA 2";
                }
            }
        }

        // Check columns
        for (std::size_t i = 0; i < 3; ++i) {
            if (_board[0][i] == _board[1][i] && _board[1][i] == _board[2][i]) {
                if (_board[0][i] == Player::IA_1) {
                    winner = "IA 1";
                } else if (_board[0][i] == Player::IA_2) {
                    winner = "IA 2";
                }
            }
        }

        // Check diagonals
        if (_board[0][0] == _board[1][1] && _board[1][1] == _board[2][2]) {
            if (_board[0][0] == Player::IA_1) {
                winner = "IA 1";
            } else if (_board[0][0] == Player::IA_2) {
                winner = "IA 2";
            }
        }

        if (_board[0][2] == _board[1][1] && _board[1][1] == _board[2][0]) {
            if (_board[0][2] == Player::IA_1) {
                winner = "IA 1";
            } else if (_board[0][2] == Player::IA_2) {
                winner = "IA 2";
            }
        }

        int count = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (_board[i][j] != Player::NONE) {
                    count++;
                }
            }
        }

        if (winner.empty() && count == 0)
            return "Tie";
        else
            return winner;
    }

    void TicTacTeo::playerTurn() {
        int x, y;
        std::cout << "Enter x: ";
        std::cin >> x;
        std::cout << "Enter y: ";
        std::cin >> y;

        if (x < 0 || x > 2 || y < 0 || y > 2) {
            std::cout << "Invalid coordinates" << std::endl;
            playerTurn();
        } else if (_board[x][y] != Player::NONE) {
            std::cout << "This cell is already taken" << std::endl;
            playerTurn();
        } else {
            _board[x][y] = Player::IA_1;
        }
    }

    void TicTacTeo::iaTurn() {
        IA::MiniMax ia(_board);
        std::pair<int, int> move = ia.getBestMove();
        std::cout << "IA 2 played: " << move.first << " " << move.second << std::endl;
        _board[move.first][move.second] = Player::IA_2;
    }

    void TicTacTeo::gameLoop() {
        std::string winner;
        while (winner.empty()) {
            playerTurn();
            displayBoard();
            std::cout << "" << std::endl;
            winner = checkWin();
            if (!winner.empty()) {
                std::cout << "Winner: " << winner << std::endl;
                break;
            }

            iaTurn();
            displayBoard();
            std::cout << "" << std::endl;
            winner = checkWin();
            if (!winner.empty()) {
                std::cout << "Winner: " << winner << std::endl;
                break;
            }
        }

    }

}// TicTacTeo
