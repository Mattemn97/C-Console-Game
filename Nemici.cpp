#include "Nemici.h"
#include "Utils.h"
#include <iostream>
#include <thread>
#include <chrono>

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
    std::cout << "&";
}

BiegaczPoz::BiegaczPoz() {
    x = 0;
    y = 0;
    vite = 2;
    direzione = 'd';
}

void BiegaczPoz::crea(int x, int y, char direzione) {
    this->x = x;
    this->y = y;
    this->direzione = direzione;
    vite = 2;
    gotoxy(x, y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    std::cout << "S";
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
    std::cout << "%";
}

// ------------------------------
// Implementazione delle torrette
// ------------------------------

// Torretta che spara in orizzontale
ArmatePoz::ArmatePoz() {
    x = 0;
    y = 0;
    attiva = false;
}

void ArmatePoz::crea(int x, int y) {
    this->x = x;
    this->y = y;
    attiva = true;
    gotoxy(x, y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    std::cout << "=";
}

void ArmatePoz::spara() {
    if (!attiva) return;
    
    for (int i = x + 1; i < x + 10; i++) {  // Spara verso destra
        gotoxy(i, y);
        std::cout << "-";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        gotoxy(i, y);
        std::cout << " ";  // Cancella il proiettile
    }
}

// Torretta che spara in verticale
ArmatePio::ArmatePio() {
    x = 0;
    y = 0;
    attiva = false;
}

void ArmatePio::crea(int x, int y) {
    this->x = x;
    this->y = y;
    attiva = true;
    gotoxy(x, y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    std::cout << "I";
}

void ArmatePio::spara() {
    if (!attiva) return;

    for (int i = y + 1; i < y + 5; i++) {  // Spara verso il basso
        gotoxy(x, i);
        std::cout << "|";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        gotoxy(x, i);
        std::cout << " ";  // Cancella il proiettile
    }
}
