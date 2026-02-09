#include "BitcoinExchange.hpp"


int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange btc;

    btc.loadDatabase("data.csv"); // On charge la DB interne
    btc.processInput(av[1]);      // On traite le fichier passé en argument

    return 0;
}