
#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: No sequence provided." << std::endl;
        return 1;
    }

    PmergeMe solver;
    try {
        solver.parseInput(argc, argv);
        solver.displayBefore();
        solver.execute();
        solver.displayResults();
        // Plus de "std::adjacent_find" ici, on le fera plus tard proprement
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}