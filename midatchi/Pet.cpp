#include <iostream>
#include <windows.h>
#include <algorithm>
#include "Pet.h"
#include <string>
#include "MidatchiWinEngine.h"


Pet::Pet(std::string name)
	:name(name)
{
	petEyes = "(o w o)";
	petBlink = "(- w -)";
}

std::string Pet::GetName() {
	return name;
}

std::string Pet::GetPetEyes() {
	return petEyes;
}

std::string Pet::GetPetBlink() {
	return petBlink;
}

void Pet::SetName(std::string newName) {
	name = newName;
}