#ifndef GIOCATORE_H
#define GIOCATORE_H

class Giocatore {
public:
    int x;
    int y;
    int vite;
    int munizioni;
    int tempoRespawn;
    char direzione;
    bool ucciso;
    int checkPoint;

    Giocatore();
    void resetPosizione();
    void subisciDanno();  // Nuova funzione
};

#endif // GIOCATORE_H
