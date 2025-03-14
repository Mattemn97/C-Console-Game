#ifndef GIOCO_H
#define GIOCO_H

#include "Giocatore.h"
#include "Nemici.h"
#include "Livello.h"

class Gioco {
public:
    Gioco();
    void aggiorna();
    bool verificaCollisione(int x, int y);
    void gestisciInput(char input);
};

#endif // GIOCO_H
