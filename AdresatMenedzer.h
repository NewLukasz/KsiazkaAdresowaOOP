#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMenedzer{
    Adresat adresat;
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    int idOstatniegoAdresta;
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
    : plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika){
        adresaci=plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        idOstatniegoAdresta=plikZAdresatami.pobierzIdOstatniegoAdresata();
    };
    void dodajAdresata();
    void wypiszWszystkichAdresatow();
    int przeslijIdOstatniegoAdresata();
    void wyswietlKontaktyWyszukanePoImieniu();
    void wyswietlKontaktyWyszukanePoNazwisku();
    void usunWybranegoAdresata();
};

#endif
