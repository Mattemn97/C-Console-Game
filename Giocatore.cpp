#include "Giocatore.h"
#include "Utils.h"
#include <iostream>

Giocatore::Giocatore() {
    x = 2;
    y = 35;
    vite = 3;
    munizioni = 15;
    punteggio = 0;
    tempoRespawn = 0;
    direzione = 'd';
    ucciso = false;
    checkPoint = 0;
}

void Giocatore::resetPosizione() {
    switch (checkPoint) {
        case 1: x = 56; y = 22; break;
        case 2: x = 4; y = 23; break;
        case 3: x = 33; y = 11; break;
        case 4: x = 42; y = 12; break;
        case 5: x = 85; y = 15; break;
        default: x = 2; y = 35; break;
    }
}

void Giocatore::subisciDanno() {
    vite--;
    std::cout << "\n💥 Il giocatore ha subito danno! Vite rimanenti: " << vite << std::endl;

    if (vite <= 0) {
        std::cout << "\n❌ GAME OVER ❌\n";
        exit(0);
    } else {
        resetPosizione();
    }
}

void Giocatore::aumentaPunteggio(int valore) {
    punteggio += valore;
    std::cout << "\n⭐ Punteggio: " << punteggio << std::endl;
}
