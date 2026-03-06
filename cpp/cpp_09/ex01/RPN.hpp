#pragma once 
#include <iostream>
#include <cstdlib>
#include <stack>
#include <sstream>


class RPN{
    private :
        std::stack<int> _s;
        bool isOperator(char c);

    public :
        RPN();
        ~RPN();
        RPN(const RPN &ohter);
        RPN &operator=(const RPN &other);

        void execute(const std::string &calcul);
};


