#include "Gioco.h"
#include "Utils.h"
#include <iostream>
#include <conio.h>

Giocatore giocatore;
Livello livello;
Scigacz nemicoInseguitore;
BiegaczPoz nemicoCorridore;
Randomer nemicoRandom;
ArmatePoz torrettaOrizzontale;
ArmatePio torrettaVerticale;

Gioco::Gioco() {
    livello.caricaMappa("level_1.txt");
    livello.generaElementi();
    
    gotoxy(giocatore.x, giocatore.y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    std::cout << "P";

    // Creiamo torrette per test
    torrettaOrizzontale.crea(30, 10);
    torrettaVerticale.crea(50, 5);
}

void Gioco::aggiorna() {
    while (true) {
        if (_kbhit()) {  
            char input = getch();
            gestisciInput(input);
        }

        rilevaDanno();  // Controlla se il giocatore viene colpito
        torrettaOrizzontale.spara();
        torrettaVerticale.spara();
    }
}

bool Gioco::verificaCollisione(int x, int y) {
    gotoxy(x, y);
    char c = getCursorChar();
    return (c == '#' || c == '-' || c == '|');
}

void Gioco::gestisciInput(char input) {
    gotoxy(giocatore.x, giocatore.y);
    std::cout << " ";

    switch (input) {
        case 'w': if (!verificaCollisione(giocatore.x, giocatore.y - 1)) giocatore.y--; break;
        case 's': if (!verificaCollisione(giocatore.x, giocatore.y + 1)) giocatore.y++; break;
        case 'a': if (!verificaCollisione(giocatore.x - 1, giocatore.y)) giocatore.x--; break;
        case 'd': if (!verificaCollisione(giocatore.x + 1, giocatore.y)) giocatore.x++; break;
        case 'm':  // Simulazione di sparo
            gotoxy(giocatore.x, giocatore.y - 1);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            std::cout << "o";
            break;
        case 'r': giocatore.resetPosizione(); break;
        case 27: exit(0);  // ESC per uscire
    }

    gotoxy(giocatore.x, giocatore.y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    std::cout << "P";
}

// Funzione per rilevare se il giocatore è colpito
void Gioco::rilevaDanno() {
    gotoxy(giocatore.x, giocatore.y);
    char c = getCursorChar();

    if (c == '-' || c == '|') {
        giocatore.subisciDanno();
    }
}
