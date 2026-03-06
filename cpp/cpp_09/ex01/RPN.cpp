#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const RPN &other){
    this->_s = other._s;
}

RPN &RPN::operator=(const RPN &other){
    if(this != &other){
        this->_s = other._s;
    }
    return *this;
}


bool RPN::isOperator(char c){
    return(c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::execute(const std::string &calcul){
    std::stringstream ss(calcul);
    std::string t;


    while(ss >> t){
        if(t.length() > 1){
            std::cerr << "Error : number too big" << std::endl;
            return;
        }
        char c = t[0];
        if(isdigit(c)){
            _s.push(c - '0');
        }
        else if(isOperator(c)){
            if(_s.size() < 2){
                std::cerr << "Error : not enough number to calculate" << std::endl;
                return;
            }
            int b = _s.top();
            _s.pop();
            int a = _s.top();
            _s.pop();
            if(c == '+') {
                _s.push(a + b);
            }
            else if (c == '-'){
                _s.push(a - b);
            }
            else if(c == '*'){
                _s.push(a * b);
            }
            else if(c == '/'){
                if(b == 0){
                    std::cerr << "Error : divison per 0 impossible" << std::endl;
                    return;
                }
                _s.push(a / b);
            }
        }
        else{
            std::cerr << "Error: operator is not allowed" << std::endl;
            return;
        }
    }
    if(_s.size() == 1){
        std::cout << _s.top() << std::endl;
    }
    else{
        std::cerr << "Error" << std::endl;
    }
}