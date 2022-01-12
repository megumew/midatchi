#include "MidatchiWinEngine.h"
#include <iostream>
#include <windows.h>
#include <algorithm>
#include "Pet.h"
#include <string>
#include <ctime>

struct tm newtime;
__time32_t aclock;


MidatchiWinEngine::MidatchiWinEngine() {
	statusHunger = "~";
	statusFun = "c:";
	status3 = "?";
}

void MidatchiWinEngine::Welcome() {
    std::cout << "WELCOME TO MIDATCHI!\n~~~~~~~~~~~~~~~~~~~\npress ENTER to play";
    std::cin.ignore();
    Clear();
}

void MidatchiWinEngine::Menu() {
    std::cout << "///MIDATCHI///MIDATCHI///MIDATCHI///MIDATCHI///MIDATCHI///\n1\tPLAY\n2\tGALLERY\n3\tSETTINGS\n4\tSAVES\n5\tQUIT" << std::endl;

    std::string choice;

    bool onMenu = true;

    while (onMenu) {
        std::cin >> choice;
        int c = std::stoi(choice);
        if (c != NULL) {
            switch (c) {
            case 1:
                onMenu = false;
                break;
            case 2:
                std::cout << "Under Construction!" << std::endl;
                break;
            case 3:
                std::cout << "Under Construction!" << std::endl;
                break;
            case 4:
                std::cout << "Under Construction!" << std::endl;
                break;
            case 5:
                exit(0);
            default:
                std::cout << "Please enter a valid response." << std::endl;
            }
        }

    }

    Clear();
}


Pet MidatchiWinEngine::PetCreation() {

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
            if (yesNo[0] == 'y') {
                naming = false;
                needConfirm = false;
            }
            else {
                needConfirm = false;
            }
        }
    }

    Clear();

    Pet pet(name);
    std::cout << "Pet successfully created with name " << pet.GetName() << "." << std::endl;
    std::cout << "Press Enter to Continue" << std::endl;
    std::cin.ignore();
    std::cin.get();
    Clear();

    return pet;

}


void MidatchiWinEngine::Play(Pet pet) {
    bool running = true;
    std::string curTime;
    std::string lastTime;

    while (running) {
        lastTime = curTime;
        curTime = getTime();

        if (lastTime != curTime) {
            Clear();
            std::cout << pet.GetName() + ":\t" + statusHunger + " " + statusFun + " " + status3 + "\n\t" + "\n\t" + pet.GetPet() + "\n" << curTime << std::endl;
        }


    }


}

std::string MidatchiWinEngine::getTime() {

    char buffer[32];
    errno_t errNum;
    _time32(&aclock);   // Get time in seconds.
    _localtime32_s(&newtime, &aclock);   // Convert time to struct tm form

    errNum = asctime_s(buffer, 32, &newtime);
    if (errNum)
    {
        return "error";
    }
    return buffer;
}

void MidatchiWinEngine::Clear() {
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