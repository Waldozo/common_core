#include "Harl.hpp"

int getLevel(std::string str) {
    if (str == "DEBUG") return 0;
    if (str == "INFO") return 1;
    if (str == "WARNING") return 2;
    if (str == "ERROR") return 3;
    return -1;
}

int main(int argc, char **argv)
{

    if(argc != 2)
    {
        std::cout << RED << "Need an argument" << std::endl;
        return 1;
    }
    Harl harl;

    std::string str = argv[1];

    switch (getLevel(str)) {
        case 0:
            harl.complain("DEBUG");
            break;
        case 1:
            harl.complain("INFO");
            break;
        case 2:
            harl.complain("WARNING");
            break;
        case 3:
            harl.complain("ERROR");
            break;
        default:
            std::cout << BLUE << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
    return 0;
}