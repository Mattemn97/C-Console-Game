# Gioco Console in C++

## Descrizione
Questa applicazione, scritta in C++, implementa un ambiente ludico basato su console, caratterizzato da una struttura interattiva in cui il giocatore gestisce un'entità virtuale con l'obiettivo di superare ostacoli, sconfiggere avversari e raccogliere risorse utili. Il sistema sfrutta le API di Windows per il controllo della console, inclusa la manipolazione del buffer video per la gestione della posizione del cursore e delle proprietà cromatiche dell'output.

## Funzionalità principali
- **Sistema di controllo vettoriale** del personaggio attraverso l'interfaccia W, A, S, D
- **Meccanismo di proiezione balistica** mediante attivazione del tasto M
- **Gestione dinamica degli oggetti di gioco**, inclusi potenziamenti di munizioni, checkpoint per la ripresa del gioco e ripristini delle risorse vitali
- **Modello di intelligenza artificiale per avversari**, comprendente entità statiche, inseguitori a traiettoria adattiva e boss con parametri evolutivi
- **Algoritmo di checkpoint** per la gestione degli stati di salvataggio progressivo
- **Struttura gerarchica del menu**, con opzioni di configurazione avanzata e selezione del livello di difficoltà
- **Rendering testuale degli ambienti** tramite parsing di file di livello predefiniti

## Interazione e Controlli
- **W** - Traslazione positiva lungo l’asse Y
- **A** - Traslazione negativa lungo l’asse X
- **S** - Traslazione negativa lungo l’asse Y
- **D** - Traslazione positiva lungo l’asse X
- **M** - Attivazione del sistema di combattimento a distanza
- **ESC** - Ritorno al menu di configurazione
- **R** - Reset dell'ultima posizione di checkpoint (con decremento delle risorse vitali)

## Procedura di Installazione ed Esecuzione
1. Verificare la presenza di un compilatore C++ compatibile con ambiente Windows, come MinGW o Microsoft Visual Studio.
2. Compilare il codice sorgente mediante il comando:
   ```sh
   g++ Game.cpp -o Game.exe -static -mwindows
   ```
3. Eseguire l'applicativo con:
   ```sh
   Game.exe
   ```

## Dipendenze Software
- **Windows API**, per la gestione delle operazioni su console
- **Librerie standard C++**, tra cui `iostream`, `cstdlib`, `windows.h`, `conio.h`, `fstream`, `ctime`

## Considerazioni Aggiuntive
- Il gioco effettua il caricamento delle strutture ambientali tramite parsing di file testuali di configurazione (es. `level_1.txt`).
- È implementata una funzione di tuning dinamico della velocità di gioco tramite menu dedicato.
- Parte della nomenclatura interna al codice è in lingua polacca, sebbene non impatti sulle meccaniche fondamentali di gameplay.

## Autore
Matteo Filippini

