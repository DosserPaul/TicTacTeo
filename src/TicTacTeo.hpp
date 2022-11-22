//
// Created by kiwi on 20/11/22.
//

#ifndef TICTACTOE_TICTACTEO_HPP
#define TICTACTOE_TICTACTEO_HPP

#include <iostream>
#include <string>
#include <vector>
#include <limits>

namespace TicTacTeo {

    class TicTacTeo {
        public:
            enum Player {
                IA_1 = -1,
                IA_2 = 1,
                NONE = 0,
                TIE = 2
            };

            explicit TicTacTeo();
            ~TicTacTeo() = default;

            // Getters
            std::string checkWin();

    private:
            // Variables
            std::vector<std::vector<int>> _board;


            // Methods
            void initBoard();
            void displayBoard();

            void playerTurn();
            void iaTurn();

            void gameLoop();
    };

} // TicTacTeo

#endif //TICTACTOE_TICTACTEO_HPP
