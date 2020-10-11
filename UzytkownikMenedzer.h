#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "PlikZUzytkownikami.h"
#include "Uzytkownik.h"
#include "AdresatMenedzer.h"

using namespace std;

class UzytkownikMenedzer {
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;
    PlikZUzytkownikami plikZUzytkownikami;


    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    void wyswietlMenuNiezalogowanegoUzytkownika();
    char wybierzOpcjeZMenuGlownego();
    char wczytajZnak();
    int logowanieUzytkownika();
    string wczytajLinie();


public:
    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami);
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
};
#endif
