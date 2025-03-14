#include "Livello.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
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
        std::cout << riga << std::endl;  // Stampa la mappa a schermo
    }
    file.close();
}

void Livello::generaElementi() {
    // Simulazione della generazione di elementi nel livello
    std::cout << "Generazione degli elementi del livello..." << std::endl;
    
    // Creiamo alcuni oggetti per testare
    creaSkrzynie(10, 10);
    creaZbierajkeZycie(15, 5);
    creaZbierajkeMunizioni(20, 8);
    creaZbierajkeCheckPoint(30, 12);
}

// Funzione per creare una cassa
void Livello::creaSkrzynie(int x, int y) {
    gotoxy(x, y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    std::cout << "@";  // Simbolo per la cassa
}

// Funzione per creare un potenziamento vita
void Livello::creaZbierajkeZycie(int x, int y) {
    gotoxy(x, y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    std::cout << "+";  // Simbolo per vita extra
}

// Funzione per creare un potenziamento munizioni
void Livello::creaZbierajkeMunizioni(int x, int y) {
    gotoxy(x, y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    std::cout << "A";  // Simbolo per munizioni
}

// Funzione per creare un checkpoint
void Livello::creaZbierajkeCheckPoint(int x, int y) {
    gotoxy(x, y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
    std::cout << "C";  // Simbolo per il checkpoint
}
