#include "Gioco.h"
#include "Utils.h"
#include <iostream>
#include <conio.h>

Giocatore giocatore;
Livello livello;
Scigacz nemicoInseguitore;
BiegaczPoz nemicoCorridore;
Randomer nemicoRandom;

Gioco::Gioco() {
    livello.caricaMappa("level_1.txt");
    livello.generaElementi();
    
    // Posizioniamo il giocatore inizialmente
    gotoxy(giocatore.x, giocatore.y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    std::cout << "P";
}

void Gioco::aggiorna() {
    while (true) {
        if (_kbhit()) {  
            char input = getch();
            gestisciInput(input);
        }
    }
}

bool Gioco::verificaCollisione(int x, int y) {
    gotoxy(x, y);
    char c = getCursorChar();
    return (c == '#' || c == '-' || c == '|');
}

void Gioco::gestisciInput(char input) {
    gotoxy(giocatore.x, giocatore.y);
    std::cout << " ";  // Cancella la posizione precedente

    switch (input) {
        case 'w':
            if (!verificaCollisione(giocatore.x, giocatore.y - 1)) {
                giocatore.y -= 1;
            }
            break;
        case 's':
            if (!verificaCollisione(giocatore.x, giocatore.y + 1)) {
                giocatore.y += 1;
            }
            break;
        case 'a':
            if (!verificaCollisione(giocatore.x - 1, giocatore.y)) {
                giocatore.x -= 1;
            }
            break;
        case 'd':
            if (!verificaCollisione(giocatore.x + 1, giocatore.y)) {
                giocatore.x += 1;
            }
            break;
        case 'm':  // Simulazione di sparo
            gotoxy(giocatore.x, giocatore.y - 1);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            std::cout << "o";
            break;
        case 'r':  // Ripristina il checkpoint
            giocatore.resetPosizione();
            break;
        case 27:  // ESC per uscire
            exit(0);
    }

    // Ridisegna il giocatore
    gotoxy(giocatore.x, giocatore.y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    std::cout << "P";
}
