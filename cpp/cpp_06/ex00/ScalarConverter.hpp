#pragma once
#include <iostream>
#include <cstdlib>
#include <limits>
#include <sstream>


class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter &operator=(const ScalarConverter &copy);
        ~ScalarConverter();

        static void printChar(char c);

    public:
        static void convert(const std::string str);
};

