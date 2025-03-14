#include "Giocatore.h"

Giocatore::Giocatore() {
    x = 2;
    y = 35;
    vite = 3;
    munizioni = 15;
    tempoRespawn = 0;
    direzione = 'd';  // Default: verso destra
    ucciso = false;
    checkPoint = 0;
}

void Giocatore::resetPosizione() {
    switch (checkPoint) {
        case 1:
            x = 56; y = 22; break;
        case 2:
            x = 4; y = 23; break;
        case 3:
            x = 33; y = 11; break;
        case 4:
            x = 42; y = 12; break;
        case 5:
            x = 85; y = 15; break;
        default:
            x = 2; y = 35; break;
    }
}
