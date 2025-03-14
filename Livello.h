#ifndef LIVELLO_H
#define LIVELLO_H

#include <string>

class Livello {
public:
    Livello();
    void caricaMappa(const std::string& nomeFile);
    void generaElementi();
};

#endif // LIVELLO_H
