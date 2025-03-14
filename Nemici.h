#ifndef NEMICI_H
#define NEMICI_H

class Scigacz {
public:
    int x, y;
    bool esiste;
    int velocità;

    Scigacz();
};

class BiegaczPoz {
public:
    int x, y;
    int vite;
    char direzione;

    BiegaczPoz();
};

class Randomer {
public:
    int x, y;
    int xMin, xMax, yMin, yMax;
    int vite;
    bool movimentoRiuscito;
    int velocità;

    Randomer();
};

#endif // NEMICI_H
