#ifndef NEMICI_H
#define NEMICI_H

#include <windows.h>

class Scigacz {
public:
    int x, y;
    bool esiste;
    int velocità;

    Scigacz();
    void crea(int x, int y);
    void muovi(int px, int py);  // IA per inseguire il giocatore
};

class BiegaczPoz {
public:
    int x, y;
    int vite;
    char direzione;

    BiegaczPoz();
    void crea(int x, int y, char direzione);
    void muovi();  // Movimento orizzontale automatico
};

class Randomer {
public:
    int x, y;
    int xMin, xMax, yMin, yMax;
    int vite;
    bool movimentoRiuscito;
    int velocità;

    Randomer();
    void crea(int x, int y, int area, int velocità);
    void muovi();  // Movimento casuale
};

#endif // NEMICI_H
