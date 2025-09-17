#include "Zombie.hpp"

int main(){
    Zombie* myHorde = zombieHorde(5, "Dilaw");
    myHorde[0].announce();
    myHorde[1].announce();
    myHorde[2].announce();
    myHorde[3].announce();
    myHorde[4].announce();


    delete[] myHorde;
}