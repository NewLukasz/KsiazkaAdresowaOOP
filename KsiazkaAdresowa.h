#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenedzer.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class KsiazkaAdresowa {
    UzytkownikMenedzer uzytkownikMenedzer;
    PlikZUzytkownikami plikZUzytkownikami;

public:
    vector <Uzytkownik> uzytkownicy;
    vector <Uzytkownik> wczytajUzytkownikowZPliku();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
};
#endif
