#pragma once
#include <string>
class Pet
{
public:
	Pet(std::string name);
	std::string GetName();
	std::string GetPetEyes();
	std::string GetPetBlink();
	void SetName(std::string);
private:
	std::string name;
	std::string petEyes;
	std::string petBlink;
};

