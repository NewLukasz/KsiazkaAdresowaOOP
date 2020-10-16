#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
using namespace std;

class AdresatMenedzer{
    Adresat adresat;
    vector <Adresat> adresaci;

public:
    void dodajAdresata();
    void wypiszWszystkichAdresatow();
};

#endif
