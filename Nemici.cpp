#include "Nemici.h"
#include "Utils.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
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

// IA: Insegue il giocatore
void Scigacz::muovi(int px, int py) {
    if (!esiste) return;

    gotoxy(x, y);
    std::cout << " ";

    if (x < px) x++;
    else if (x > px) x--;

    if (y < py) y++;
    else if (y > py) y--;

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

// Movimento orizzontale automatico
void BiegaczPoz::muovi() {
    gotoxy(x, y);
    std::cout << " ";

    if (direzione == 'd') {
        x++;
        if (getCursorChar() == '#') {
            direzione = 'a';
            x -= 2;
        }
    } else {
        x--;
        if (getCursorChar() == '#') {
            direzione = 'd';
            x += 2;
        }
    }

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

// Movimento casuale
void Randomer::muovi() {
    gotoxy(x, y);
    std::cout << " ";

    int dx = (rand() % 3) - 1;  // -1, 0, 1
    int dy = (rand() % 3) - 1;

    if (x + dx >= xMin && x + dx <= xMax) x += dx;
    if (y + dy >= yMin && y + dy <= yMax) y += dy;

    gotoxy(x, y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
    std::cout << "%";
}
