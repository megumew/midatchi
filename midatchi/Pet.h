#pragma once
#include <string>
class Pet
{
public:
	Pet(std::string name);
	std::string GetName();
	std::string GetPet();
	void SetName(std::string);
private:
	std::string name;
	std::string petEyes;
	std::string petBlink;
	bool blinking;
};

