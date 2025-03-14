#include <iostream>
#include "Gioco.h"
#include "Utils.h"

void menu();
void avviaGioco(int difficolta);

int main() {
    SetWindow(113, 44);
    menu();
    return 0;
}

void menu() {
    char scelta;
    int difficolta = 2;  

    do {
        system("CLS");
        std::cout << "=== MENU PRINCIPALE ===\n";
        std::cout << "1. Avvia Gioco (Facile)\n";
        std::cout << "2. Avvia Gioco (Medio)\n";
        std::cout << "3. Avvia Gioco (Difficile)\n";
        std::cout << "4. Mostra Legenda\n";
        std::cout << "5. Resetta Gioco\n";
        std::cout << "6. Esci\n";
        std::cout << "Scelta: ";
        std::cin >> scelta;

        switch (scelta) {
            case '1':
                difficolta = 1;
                avviaGioco(difficolta);
                break;
            case '2':
                difficolta = 2;
                avviaGioco(difficolta);
                break;
            case '3':
                difficolta = 3;
                avviaGioco(difficolta);
                break;
            case '4':
                mostraLegenda();
                system("pause");
                break;
            case '5':
                std::cout << "Resetting game...\n";
                system("pause");
                menu();
                break;
            case '6':
                std::cout << "Uscita dal gioco...\n";
                break;
            default:
                std::cout << "Scelta non valida! Riprova.\n";
                system("pause");
        }
    } while (scelta != '6');
}

void avviaGioco(int difficolta) {
    system("CLS");
    Gioco gioco(difficolta);
    gioco.aggiorna();
}
