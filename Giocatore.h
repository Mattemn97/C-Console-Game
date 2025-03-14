#ifndef GIOCATORE_H
#define GIOCATORE_H

class Giocatore {
public:
    int x, y;
    int vite;
    int munizioni;
    int punteggio;
    int tempoRespawn;
    char direzione;
    bool ucciso;
    int checkPoint;

    Giocatore();
    void resetPosizione();
    void subisciDanno();
    void aumentaPunteggio(int valore);
};

#endif // GIOCATORE_H
