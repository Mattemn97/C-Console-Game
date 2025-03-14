#ifndef GIOCO_H
#define GIOCO_H

#include "Giocatore.h"
#include "Nemici.h"
#include "Livello.h"

class Gioco {
public:
    int difficolta;  // 1 = Facile, 2 = Medio, 3 = Difficile

    Gioco(int livelloDifficolta);
    void aggiorna();
    bool verificaCollisione(int x, int y);
    void gestisciInput(char input);
    void rilevaDanno();
    
    // Nuove funzioni
    void wyczyscTablice();
    void impostaVelocita(int livello);
};

#endif // GIOCO_H
