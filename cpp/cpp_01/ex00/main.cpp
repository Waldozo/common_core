#include "Zombie.hpp"

int main(){
    randomChump("Stacky");

    Zombie* ZombieHeap = newZombie("Happy");
    
    ZombieHeap -> announce();

    delete ZombieHeap;

    return 0;
}