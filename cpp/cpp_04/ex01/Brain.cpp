#include "Brain.hpp"

Brain::Brain(){
    std::cout << "Brain constructor called" << std::endl;
    for(int i = 0; i < 100; i++)
    {
        ideas[i] = "";
    }
}

Brain::Brain(const Brain &other){
    std::cout << "Constructor de copy Brain called" << std::endl;
    for(int i = 0; i < 100; i++){
        ideas[i] = other.ideas[i];
    }
}

Brain &Brain::operator=(const Brain &other) {
    if(this != &other){
        for(int i = 0; i < 100; i++){
            ideas[i] = other.ideas[i];
        }
    }
    return(*this);
}

Brain::~Brain(){
    std::cout << "Brain destructor called" << std::endl;
}
