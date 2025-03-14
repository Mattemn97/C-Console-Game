#ifndef LIVELLO_H
#define LIVELLO_H

#include <string>

class Livello {
public:
    Livello();
    void caricaMappa(const std::string& nomeFile);
    void generaElementi();
    
    void creaSkrzynie(int x, int y);
    void creaZbierajkeZycie(int x, int y);
    void creaZbierajkeMunizioni(int x, int y);
    void creaZbierajkeCheckPoint(int x, int y);
    void creaBoss(int x, int y);
    
    // Nuove funzioni
    void tworzBossaPokonany(int x, int y);
    void tworzBossa1Raz(int x, int y);
};

#endif // LIVELLO_H
