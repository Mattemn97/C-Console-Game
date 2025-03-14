#include "Nemici.h"
#include "Utils.h"
#include <iostream>

Scigacz::Scigacz() {
    x = 0;
    y = 0;
    esiste = false;
    velocità = 1;
}

void Scigacz::crea(int x, int y) {
    this->x = x;
    this->y = y;
    esiste = true;
    gotoxy(x, y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    std::cout << "&";  // Simbolo per il nemico che insegue
}

BiegaczPoz::BiegaczPoz() {
    x = 0;
    y = 0;
    vite = 2;
    direzione = 'd';  // Default: si muove a destra
}

void BiegaczPoz::crea(int x, int y, char direzione) {
    this->x = x;
    this->y = y;
    this->direzione = direzione;
    vite = 2;
    gotoxy(x, y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    std::cout << "S";  // Simbolo per il nemico che si muove orizzontalmente
}

Randomer::Randomer() {
    x = 0;
    y = 0;
    xMin = 0;
    xMax = 0;
    yMin = 0;
    yMax = 0;
    vite = 2;
    movimentoRiuscito = false;
    velocità = 2;
}

void Randomer::crea(int x, int y, int area, int velocità) {
    this->x = x;
    this->y = y;
    xMin = x - area;
    xMax = x + area;
    yMin = y - area;
    yMax = y + area;
    this->velocità = velocità;
    vite = 2;
    gotoxy(x, y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
    std::cout << "%";  // Simbolo per il nemico che si muove casualmente
}
