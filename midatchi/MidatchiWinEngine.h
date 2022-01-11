#pragma once
#include "Pet.h"
#include <string>

class MidatchiWinEngine
{
public:
	MidatchiWinEngine();
	void Welcome();
	void Clear();
	void Menu();
	Pet PetCreation();
	void Play(Pet pet);
	std::string getTime();
private:
	std::string statusHunger;
	std::string statusFun;
	std::string status3;

};

