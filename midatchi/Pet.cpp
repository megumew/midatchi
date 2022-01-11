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
	blinking = false;
}

std::string Pet::GetName() {
	return name;
}

std::string Pet::GetPet() {
	if (blinking) {
		blinking = !blinking;
		return petBlink;
	}
	else {
		blinking = !blinking;
		return petEyes;
	}
}
void Pet::SetName(std::string newName) {
	name = newName;
}