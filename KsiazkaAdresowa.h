#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenedzer.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class KsiazkaAdresowa {
    UzytkownikMenedzer uzytkownikMenedzer;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami) {};
    vector <Uzytkownik> uzytkownicy;
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    char wybierzOpcjeZMenuUzytkownika();
    char wybierzOpcjeZMenuGlownego();
    int logowanieUzytkownika();
};
#endif
