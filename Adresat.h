#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>

using namespace std;

class Adresat{
    int id, idUzytkownika;
    string imie,nazwisko,numerTelefonu,email,adres;
public:
    Adresat(int =0,int =0, string ="", string ="", string ="", string ="",string ="" );
    void wypiszDaneAdresata();
};

#endif
