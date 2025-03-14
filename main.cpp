#include <iostream>
#include "Giocatore.h"
#include "Nemici.h"
#include "Livello.h"
#include "Utils.h"

void menu();
void avviaGioco();

int main() {
    SetWindow(113, 44);
    menu();
    return 0;
}

void menu() {
    char scelta;
    do {
        system("CLS");
        std::cout << "=== MENU PRINCIPALE ===\n";
        std::cout << "1. Avvia Gioco\n";
        std::cout << "2. Esci\n";
        std::cout << "Scelta: ";
        std::cin >> scelta;

        switch (scelta) {
            case '1':
                avviaGioco();
                break;
            case '2':
                std::cout << "Uscita dal gioco...\n";
                break;
            default:
                std::cout << "Scelta non valida! Riprova.\n";
                system("pause");
        }
    } while (scelta != '2');
}

void avviaGioco() {
    system("CLS");
    Giocatore giocatore;
    Livello livello;
    
    livello.caricaMappa("level_1.txt");
    livello.generaElementi();
    
    gotoxy(giocatore.x, giocatore.y);
    std::cout << "P";  // Simbolo del giocatore
    
    std::cout << "\nPremi un tasto per tornare al menu...\n";
    system("pause");
}
