#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <cstdlib>

#include "KsiazkaAdresowa.h"

using namespace std;

class AdresatMenedzer{
    void wyswietlMenuZalogowaneUzytkownika();
    char wybierzOpcjeZMenuUzytkownika();
    char wczytajZnak();
public:
    AdresatMenedzer(int idZalogowanegoUzytkownika);
};

#endif
