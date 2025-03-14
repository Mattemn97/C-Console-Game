#include "Livello.h"
#include <iostream>
#include <fstream>

Livello::Livello() {
    // Costruttore vuoto, può essere esteso in futuro
}

void Livello::caricaMappa(const std::string& nomeFile) {
    std::ifstream file(nomeFile);
    if (!file.is_open()) {
        std::cerr << "Errore: impossibile aprire il file del livello: " << nomeFile << std::endl;
        return;
    }

    std::string riga;
    while (std::getline(file, riga)) {
        std::cout << riga << std::endl;  // Stampa la mappa a schermo
    }
    file.close();
}

void Livello::generaElementi() {
    // Qui andrebbero posizionati nemici, potenziamenti e checkpoint
    std::cout << "Generazione degli elementi del livello..." << std::endl;
}
