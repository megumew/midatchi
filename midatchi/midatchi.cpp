#include <iostream>
#include <windows.h>
#include <algorithm>
#include "Pet.h"

void clear();
void menu();
std::string petCreation();


int main()
{

    menu();
    Pet pet(petCreation());

    std::cout << "Pet successfully created with name " << pet.GetName() << std::endl;
}


void menu() {
    std::cout << "WELCOME TO MIDATCHI!\n~~~~~~~~~~~~~~~~~~~\npress ENTER to play";
    std::cin.ignore();
    clear();
}

std::string petCreation() {

    bool naming = true;
    bool needConfirm = true;
    std::string name;
    std::string yesNo;

    while (naming) {
        std::cout << "Please enter your pets name : ";
        std::cin >> name;
        needConfirm = true;
        while (needConfirm) {
            std::cout << "Are you sure you want your pet to be named " << name << "? [ (y)es / (n)o ]" << std::endl;
            std::cin >> yesNo;
            std::transform(yesNo.begin(), yesNo.end(), yesNo.begin(), ::tolower);
            if (yesNo == "yes" || yesNo == "y") {
                naming = false;
                needConfirm = false;
            }
            else {
                needConfirm = false;
            }
        }
    }

    clear();

    return name;
}


void clear() {
    COORD topLeft = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}