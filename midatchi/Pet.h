#pragma once
class Pet
{
public:
	Pet(std::string name);
	std::string GetName();
	void SetName(std::string);
private:
	std::string name;
};

