#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other){
    this->_db = other._db;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other){
    if(this != &other)
    {
        this->_db = other._db;
    }
    return *this;
}

std::string BitcoinExchange::trim(const std::string& str) const {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

void BitcoinExchange::loadDatabase(const std::string &filename){
    std::ifstream file(filename.c_str());

    if(!file.is_open()){
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line); //lire la premiere ligne pour rien

    while(std::getline(file, line)){
        std::stringstream ss(line);
        std::string date;
        std::string rateStr;

        if(std::getline(ss, date, ',') && std::getline(ss, rateStr)){//extraction de 'date' et 'value', on decoupe a la virgule{
            char *end;
            double value = std::strtod(rateStr.c_str(), &end); //convertion du texte en nombre
            if(*end != '\0' && !isspace(*end)){
                std::cerr << "Error: bad input =>" << rateStr << std::endl;
            }
            else if(value < 0){
                std::cerr << "Error: Negatif number" << std::endl;
            }
            else{
                this->_db[date] = value;
            }
        }
    }
    file.close();
}

void BitcoinExchange::processInput(const std::string &filename){
    std::ifstream file(filename.c_str());
    
    if(!file.is_open()){
        std::cerr << "Error: Could not open file" << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    
    while(std::getline(file, line)){
        
        
        std::stringstream ss(line);
        std::string date;
        std::string pipe;
        double value;

        size_t delim = line.find('|');

        if(delim == std::string::npos){
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        date = line.substr(0, delim);
        date = trim(date);
        std::string valueStr = line.substr(delim + 1);
        char *end;

        value = std::strtod(valueStr.c_str(), &end);
        if(value < 0){
            std::cerr << "Error: not a positive number." << std::endl;
        }
        else if(value > 1000){
            std::cerr << "Error: too large a number." << std::endl;
        }
        else if (valueStr.find_first_not_of(" 0123456789.-") != std::string::npos){
            std::cerr << "Error: value has to be a number => " << line << std::endl;
        }
        else {
        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        // Initialisation de l'iterateur avec upper_bound
        std::map<std::string, double>::iterator it = _db.upper_bound(date);

        if (it == _db.begin()) {
            std::cerr << "Error: no data found for this date." << std::endl;
        }
        else{
            --it;
            double result = value * it->second;
            std::cout << date << " => " << value << " = " << result << std::endl;
        }
        }
    }
}

bool   BitcoinExchange::isValidDate(const std::string &date) const {
    if(date.length() != 10){
        return false;
    }
    if(date[4] != '-' || date[7] != '-'){
        return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if(month < 1 || month > 12){
        return false;
    }
    if(day < 1 || day > 31){
        return false;
    }
    if(month == 4 || month == 6 || month == 9 || month == 11){
        if(day > 30){
            return false;
        }
    }
    if(month == 2){
        bool bissextile = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));

        int maxdays;
        if (bissextile){
            maxdays = 29;
        }
        else{
            maxdays = 28;
        }

        if(day > maxdays){
            return false;
        }
    }
    return true;
}