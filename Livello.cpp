#include "Livello.h"
#include "Utils.h"
#include <iostream>
#include <windows.h>

Livello::Livello() {
    // Costruttore vuoto, può essere esteso
}

void Livello::caricaMappa(const std::string& nomeFile) {
    std::ifstream file(nomeFile);
    if (!file.is_open()) {
        std::cerr << "Errore: impossibile aprire il file del livello: " << nomeFile << std::endl;
        return;
    }

    std::string riga;
    while (std::getline(file, riga)) {
        std::cout << riga << std::endl;
    }
    file.close();
}

void Livello::generaElementi() {
    std::cout << "Generazione degli elementi del livello..." << std::endl;
    
    // Generazione di oggetti di gioco
    creaSkrzynie(10, 10);
    creaZbierajkeZycie(15, 5);
    creaZbierajkeMunizioni(20, 8);
    creaZbierajkeCheckPoint(30, 12);

    // Generazione del boss
    creaBoss(50, 20);
}

// Funzione per creare il boss sulla console
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
    gotoxy(x - 3, y + 4);
    std::cout << "XXX XXXXX XXX";
    gotoxy(x - 3, y + 5);
    std::cout << "XX   XXX   XX";
    gotoxy(x - 3, y + 6);
    std::cout << "XXX XX XX XXX";
    gotoxy(x - 3, y + 7);
    std::cout << "XXXXXX XXXXXX";
    gotoxy(x - 2, y + 8);
    std::cout << "XXXXXXXXXXX";
    gotoxy(x - 2, y + 9);
    std::cout << "X  XXXXX  X";
    gotoxy(x - 2, y + 10);
    std::cout << "XX X X X XX";
    gotoxy(x - 1, y + 11);
    std::cout << "X       X";
    gotoxy(x - 1, y + 12);
    std::cout << "X       X";
    gotoxy(x - 1, y + 13);
    std::cout << "XX X X XX";
    gotoxy(x - 1, y + 14);
    std::cout << "XXXXXXXXX";
    gotoxy(x, y + 15);
    std::cout << "XXXXXXX";
    gotoxy(x + 1, y + 16);
    std::cout << "XXXXX";
    gotoxy(x + 1, y + 17);
    std::cout << "XXXXX";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    gotoxy(x + 15, y - 5);
    std::cout << "#";  // Simbolo del punto vulnerabile del boss
}
