#include "Nemici.h"

Scigacz::Scigacz() {
    x = 0;
    y = 0;
    esiste = false;
    velocità = 1;
}

BiegaczPoz::BiegaczPoz() {
    x = 0;
    y = 0;
    vite = 2;
    direzione = 'd';  // Default: si muove a destra
}

Randomer::Randomer() {
    x = 0;
    y = 0;
    xMin = 0;
    xMax = 0;
    yMin = 0;
    yMax = 0;
    vite = 2;
    movimentoRiuscito = false;
    velocità = 2;
}
