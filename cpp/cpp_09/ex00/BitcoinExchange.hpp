#pragma once
#include <iostream>
#include <cstdlib>
#include <map>
#include <fstream>
#include <sstream>
#include <string>


class BitcoinExchange {
    private :
        std::map<std::string, double> _db; //db intern <Data, Taux> 

        bool isValidDate(const std::string &date) const;
        bool isValidValue(const std::string &value) const;
        std::string trim(const std::string &str) const;

    public :
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &copy);
        ~BitcoinExchange();

        void loadDatabase(const std::string &filename); //pour data.csv
        void processInput(const std::string &filename); //pour fichier de test
};