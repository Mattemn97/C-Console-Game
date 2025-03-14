#include "Livello.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>

std::vector<std::string> mappa;  // Vettore per memorizzare la mappa

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

    // Disegna la mappa sulla console
    for (size_t i = 0; i < mappa.size(); i++) {
        gotoxy(0, i);
        std::cout << mappa[i];
    }
}

void Livello::generaElementi() {
    std::cout << "Generazione degli elementi del livello..." << std::endl;

    // Scansiona la mappa per posizionare oggetti di gioco
    for (size_t y = 0; y < mappa.size(); y++) {
        for (size_t x = 0; x < mappa[y].size(); x++) {
            char c = mappa[y][x];

            switch (c) {
                case '#':  // Muro
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
                    break;
                case 'P':  // Posizione iniziale del giocatore
                    gotoxy(x, y);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                    std::cout << "P";
                    break;
                case 'C':  // Checkpoint
                    creaZbierajkeCheckPoint(x, y);
                    break;
                case '+':  // Vita extra
                    creaZbierajkeZycie(x, y);
                    break;
                case 'A':  // Munizioni
                    creaZbierajkeMunizioni(x, y);
                    break;
                case '&':  // Nemico inseguitore
                    nemicoInseguitore.crea(x, y);
                    break;
                case 'S':  // Nemico corridore
                    nemicoCorridore.crea(x, y, 'd');
                    break;
                case '%':  // Nemico random
                    nemicoRandom.crea(x, y, 5, 2);
                    break;
                case 'B':  // Boss
                    creaBoss(x, y);
                    break;
            }
        }
    }
}
