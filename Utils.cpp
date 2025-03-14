#include "Utils.h"
#include <iostream>

void SetWindow(int width, int height) {
    _COORD coord;
    coord.X = width;
    coord.Y = height;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = height - 1;
    Rect.Right = width - 1;

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(handle, coord);
    SetConsoleWindowInfo(handle, TRUE, &Rect);
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

char getCursorChar() {
    char c = '\0';
    CONSOLE_SCREEN_BUFFER_INFO con;
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    
    if (hcon != INVALID_HANDLE_VALUE && GetConsoleScreenBufferInfo(hcon, &con)) {
        DWORD read = 0;
        if (!ReadConsoleOutputCharacterA(hcon, &c, 1, con.dwCursorPosition, &read) || read != 1) {
            c = '\0';
        }
    }
    return c;
}

void mostraLegenda() {
    std::cout << "\n=== CONTROLLI DI GIOCO ===\n";
    std::cout << "W - Muoviti in alto\n";
    std::cout << "A - Muoviti a sinistra\n";
    std::cout << "S - Muoviti in basso\n";
    std::cout << "D - Muoviti a destra\n";
    std::cout << "M - Spara\n";
    std::cout << "R - Ripristina l'ultimo checkpoint\n";
    std::cout << "ESC - Esci dal gioco\n";
}
