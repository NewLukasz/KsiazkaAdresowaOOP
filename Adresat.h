#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>

using namespace std;

class Adresat{
    int id, idUzytkownika;
    string imie,nazwisko,numerTelefonu,email,adres;
public:
    int pobierzId();
    int pobierzIdUzytkownika();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzNumerTelefonu();
    string pobierzEmail();
    string pobierzAdres();

    void ustawId(int idDoUstawienia);
    void ustawIdUzytkownika(int idUzytkownikaDoUstawienia);
    void ustawImie(string imieDoUstawienia);
    void ustawNazwisko(string nazwiskoDoUstawienia);
    void ustawNumerTelefonu(string numerTelefonuDoUstawienia);
    void ustawEmail(string emailDoUstawienia);
    void ustawAdres(string adresDoUstawienia);

    Adresat(int =0,int =0, string ="", string ="", string ="", string ="",string ="" );
    void wypiszDaneAdresata();
};

#endif
