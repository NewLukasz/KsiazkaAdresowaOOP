#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "PlikZUzytkownikami.h"
#include "Uzytkownik.h"
using namespace std;

class UzytkownikMenedzer {
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;
    PlikZUzytkownikami plikZUzytkownikami;


    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);


public:
    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami){

        uzytkownicy=plikZUzytkownikami.wczytajUzytkownikowZPliku();

        };
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
};
#endif
