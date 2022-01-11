#include <iostream>
#include <windows.h>
#include <algorithm>
#include "Pet.h"
#include <string>
#include "MidatchiWinEngine.h"


int main()
{
    MidatchiWinEngine engine;

    engine.Welcome();
    engine.Menu();
    Pet pet = engine.PetCreation();
    engine.Play(pet);
}
