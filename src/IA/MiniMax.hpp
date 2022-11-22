//
// Created by kiwi on 21/11/22.
//

#ifndef TICTACTOE_MINIMAX_HPP
#define TICTACTOE_MINIMAX_HPP

#include <string>
#include <vector>
#include <iostream>
#include <limits>

#include "../TicTacTeo.hpp"

namespace TicTacTeo::IA {

    class MiniMax {
        public:
            explicit MiniMax(std::vector<std::vector<int>> board);
            ~MiniMax() = default;

            std::pair<int, int> getBestMove();

        private:
            // Variables
            std::vector<std::vector<int>> _board;
            int max = std::numeric_limits<int>::max();
            int min = std::numeric_limits<int>::min();

            // Methods
            int minimax(int depth, bool isMaximizing);
            int checkWin();
            bool isEquals3(std::vector<int> vec);

    };

} // IA

#endif //TICTACTOE_MINIMAX_HPP
