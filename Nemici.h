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
};

class BiegaczPoz {
public:
    int x, y;
    int vite;
    char direzione;

    BiegaczPoz();
    void crea(int x, int y, char direzione);
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
};

// Torretta fissa che spara orizzontalmente
class ArmatePoz {
public:
    int x, y;
    bool attiva;
    
    ArmatePoz();
    void crea(int x, int y);
    void spara();
};

// Torretta fissa che spara verticalmente
class ArmatePio {
public:
    int x, y;
    bool attiva;
    
    ArmatePio();
    void crea(int x, int y);
    void spara();
};

#endif // NEMICI_H
