#include "Livello.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>

std::vector<std::string> mappa;

Livello::Livello() {
    // Costruttore vuoto
}

void Livello::caricaMappa(const std::string& nomeFile) {
    std::ifstream file(nomeFile);
    if (!file.is_open()) {
        std::cerr << "Errore: impossibile aprire il file del livello: " << nomeFile << std::endl;
        return;
    }

    mappa.clear();
    std::string riga;
    while (std::getline(file, riga)) {
        mappa.push_back(riga);
    }
    file.close();

    for (size_t i = 0; i < mappa.size(); i++) {
        gotoxy(0, i);
        std::cout << mappa[i];
    }
}

void Livello::generaElementi() {
    std::cout << "Generazione degli elementi del livello..." << std::endl;

    for (size_t y = 0; y < mappa.size(); y++) {
        for (size_t x = 0; x < mappa[y].size(); x++) {
            char c = mappa[y][x];

            switch (c) {
                case '#':  
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
                    break;
                case 'P':  
                    gotoxy(x, y);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                    std::cout << "P";
                    break;
                case 'C':  
                    creaZbierajkeCheckPoint(x, y);
                    break;
                case '+':  
                    creaZbierajkeZycie(x, y);
                    break;
                case 'A':  
                    creaZbierajkeMunizioni(x, y);
                    break;
                case 'B':  
                    creaBoss(x, y);
                    break;
            }
        }
    }
}

void Livello::creaSkrzynie(int x, int y) {
    gotoxy(x, y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    std::cout << "@";
}

void Livello::creaZbierajkeZycie(int x, int y) {
    gotoxy(x, y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    std::cout << "+";
}

void Livello::creaZbierajkeMunizioni(int x, int y) {
    gotoxy(x, y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    std::cout << "A";
}

void Livello::creaZbierajkeCheckPoint(int x, int y) {
    gotoxy(x, y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
    std::cout << "C";
}

void Livello::creaBoss(int x, int y) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    gotoxy(x, y);
    std::cout << "XXXXXXX";
    gotoxy(x - 1, y + 1);
    std::cout << "XXXXXXXXX";
    gotoxy(x - 2, y + 2);
    std::cout << "XXXXXXXXXXX";
    gotoxy(x - 3, y + 3);
    std::cout << "XXXXXXXXXXXXX";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    gotoxy(x + 15, y - 5);
    std::cout << "#";
}

void Livello::tworzBossaPokonany(int x, int y) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    gotoxy(x, y);
    std::cout << "       ";
    gotoxy(x - 1, y + 1);
    std::cout << "       ";
    gotoxy(x - 2, y + 2);
    std::cout << "       ";
    gotoxy(x - 3, y + 3);
    std::cout << "  BOOM  ";
    gotoxy(x - 3, y + 4);
    std::cout << "  💥  ";
}

void Livello::tworzBossa1Raz(int x, int y) {
    gotoxy(x, y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    std::cout << "!!! ATTENZIONE !!!";
    gotoxy(x, y + 1);
    std::cout << "IL BOSS STA ARRIVANDO!";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    gotoxy(x, y);
    std::cout << "                   ";
    gotoxy(x, y + 1);
    std::cout << "                         ";
    creaBoss(x, y);
}
