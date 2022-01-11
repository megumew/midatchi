#include <iostream>
#include <windows.h>
#include <algorithm>
#include "Pet.h"

Pet::Pet(std::string name)
	:name(name)
{

}

std::string Pet::GetName() {
	return name;
}

void Pet::SetName(std::string newName) {
	name = newName;
}