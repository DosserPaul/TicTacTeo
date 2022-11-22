//
// Created by kiwi on 21/11/22.
//

#include "MiniMax.hpp"

namespace TicTacTeo::IA {

    MiniMax::MiniMax(std::vector<std::vector<int>> board) {
        _board = board;
    }

    std::pair<int, int> MiniMax::getBestMove() {
        int bestScore = std::numeric_limits<int>::min();
        std::pair<int, int> bestMove;


        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (_board[i][j] == TicTacTeo::Player::NONE) {
                    _board[i][j] = TicTacTeo::Player::IA_2;
                    int score = minimax(0, false);
                    _board[i][j] = TicTacTeo::Player::NONE;
                    if (score > bestScore) {
                        bestScore = score;
                        bestMove = std::make_pair(i, j);
                    }
                }
            }
        }
        return bestMove;
    }

    int MiniMax::minimax(int depth, bool isMaximizing) {
        int result = checkWin();
        if (result != -100) {
            if (result == TicTacTeo::Player::IA_2)
                return 10;
            else if (result == TicTacTeo::Player::IA_1)
                return -10;
            else if (result == TicTacTeo::Player::TIE)
                return 0;
        }


        if (isMaximizing) {
            int bestScore = std::numeric_limits<int>::min();
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (_board[i][j] == TicTacTeo::Player::NONE) {
                        _board[i][j] = TicTacTeo::Player::IA_2;
                        int score = minimax(depth + 1, false);
                        _board[i][j] = TicTacTeo::Player::NONE;
                        bestScore = std::max(score, bestScore);
                    }
                }
            }
            return bestScore;
        } else {
            int bestScore = std::numeric_limits<int>::max();
            for (std::size_t i = 0; i < 3; ++i) {
                for (std::size_t j = 0; j < 3; ++j) {
                    if (_board[i][j] == TicTacTeo::Player::NONE) {
                        _board[i][j] = TicTacTeo::Player::IA_1;
                        int score = minimax(depth + 1, true);
                        _board[i][j] = TicTacTeo::Player::NONE;
                        bestScore = std::min(score, bestScore);
                    }
                }
            }
            return bestScore;
        }
    }

    int MiniMax::checkWin() {
        // Check rows
        for (std::size_t i = 0; i < 3; ++i) {
            if (isEquals3({_board[i][0], _board[i][1], _board[i][2]})) {
                return _board[i][0];
            }
        }

        // Check columns
        for (std::size_t i = 0; i < 3; ++i) {
            if (isEquals3({_board[0][i], _board[1][i], _board[2][i]})) {
                return _board[0][i];
            }
        }

        // Check diagonals
        if (isEquals3({_board[0][0], _board[1][1], _board[2][2]})) {
            return _board[0][0];
        }
        if (isEquals3({_board[0][2], _board[1][1], _board[2][0]})) {
            return _board[0][2];
        }

        int count = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (_board[i][j] != 0) {
                    count++;
                }
            }
        }

        if (count == 0)
            return 2;

        return 0;
    }

    bool MiniMax::isEquals3(std::vector<int> vec) {
        if (vec[0] == vec[1] && vec[1] == vec[2] && vec[2] == vec[0])
            return true;
        else
            return false;
    }
} // IA