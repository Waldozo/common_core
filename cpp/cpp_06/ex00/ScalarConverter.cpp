#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy){
    (void)copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy){
    (void)copy;
    return *this;
}

ScalarConverter::~ScalarConverter(){   
}

void ScalarConverter::printChar(char c)
{
    if (c < 32 || c > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
}

bool hasDecimal(double value) {
    return value != static_cast<int>(value);
}

bool isWord(const std::string &str) {
    return str.find_first_not_of("0123456789.-f") != std::string::npos;
}


void ScalarConverter::convert(const std::string str)
{
    if (str.empty())
    {
        std::cout << "Error: Empty string" << std::endl;
        return;
    }
    
    int intValue = 0;
    float floatValue = 0.0f;
    double doubleValue = 0.0;
    
    if (str.length() == 1 && !isdigit(str[0])) {
        char c = str[0];
        intValue = static_cast<int>(c);
        floatValue = static_cast<float>(c);
        doubleValue = static_cast<double>(c);
        
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << intValue << std::endl;
        std::cout << "float: " << floatValue << "f" << std::endl;
        std::cout << "double: " << doubleValue << std::endl;
        return;
    }

    if (isWord(str) && str != "nan" && str != "nanf" && str != "+inf" && str != "+inff" && str != "-inf" && str != "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    std::istringstream iss(str);
    if (!(iss >> intValue))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        if (intValue >= 32 && intValue <= 126)
            std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        std::cout << "int: " << intValue << std::endl;
    }

    floatValue = static_cast<float>(std::strtod(str.c_str(), NULL));
    doubleValue = std::strtod(str.c_str(), NULL);

    if (hasDecimal(floatValue))
        std::cout << "float: " << floatValue << "f" << std::endl;
    else
        std::cout << "float: " << floatValue << ".0f" << std::endl;
    if (hasDecimal(doubleValue))
        std::cout << "double: " << doubleValue << std::endl;
    else
        std::cout << "double: " << doubleValue << ".0" << std::endl;
}