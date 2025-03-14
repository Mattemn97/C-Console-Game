#ifndef UTILS_H
#define UTILS_H

#include <windows.h>

// Imposta le dimensioni della finestra della console
void SetWindow(int width, int height);

// Posiziona il cursore nella console
void gotoxy(int x, int y);

// Legge il carattere attuale alla posizione del cursore
char getCursorChar();

// Mostra la legenda dei comandi nella console
void mostraLegenda();

#endif // UTILS_H
