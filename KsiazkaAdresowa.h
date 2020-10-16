#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class KsiazkaAdresowa {
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer adresatMenedzer;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami) {};
    vector <Uzytkownik> uzytkownicy;
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();

    char wybierzOpcjeZMenuUzytkownika();
    char wybierzOpcjeZMenuGlownego();
    int logowanieUzytkownika();

    void dodajAdresata();
    void wypiszDaneWszytkichAdresatow();
};
#endif
