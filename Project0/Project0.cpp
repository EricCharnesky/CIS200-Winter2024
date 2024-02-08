
#include <iostream>

#include "Trainer.h"

int main()
{
    std::cout << "Hello World!\n";
    FightingPet pet("Mewtwo", 151, 100);
    Trainer ash("Ash", 1, 0, 5);
    ash.addFightingPet(pet);

    
    Trainer brock(ash);
    brock.setName("Brock");
    FightingPet geodude("Geodude", 27, 10);
    brock.addFightingPet(geodude);

    brock.getFightingPet(0).setName("mewthree");

    cout << "Ash's first pet: " << ash.getFightingPet(0).getName() << endl;
    cout << "Brocks's first pet: " << brock.getFightingPet(0).getName() << endl;

}
