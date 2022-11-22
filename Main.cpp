//
// Created by kiwi on 20/11/22.
//

#include <iostream>

#include "src/TicTacTeo.hpp"

static void help() {
    std::cout << "Usage:" << std::endl;
    std::cout << "\t./tictactoe [OPTION]" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "\t-h, --help\tShow this help message." << std::endl;
    std::cout << "\t-v, --version\tShow version." << std::endl;
    std::cout << "\t-p, --player\tPlay with IA" << std::endl;
    std::cout << "\t-i, --ia\tIA vs IA" << std::endl;
}

int main(int ac, char **av) {
    if (ac != 2) {
        help();
        return 0;
    }

    std::string arg = av[1];

    if (arg == "-h" || arg == "--help") {
        help();
        return 0;
    }

    if (arg == "-v" || arg == "--version") {
        std::cout << "TicTacTeo v0.1.0" << std::endl;
        return 0;
    }

    if (arg == "-p" || arg == "--player") {
        std::cout << "Player vs IA" << std::endl;
        TicTacTeo::TicTacTeo game;
        return 0;
    }

    if (arg == "-i" || arg == "--ia") {
        std::cout << "IA vs IA" << std::endl;
        TicTacTeo::TicTacTeo game;
        return 0;
    }

    return 0;
}