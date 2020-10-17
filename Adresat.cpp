#include "Adresat.h"

Adresat::Adresat(int idTymczasowe, int idUzytkownikaTymczasowe, string imieTymczasowe, string nazwiskoTymczasowe, string numerTelefonuTymczasowy, string emailTymczasowy, string adresTymczasowy) {
    id=idTymczasowe;
    idUzytkownika=idUzytkownikaTymczasowe;
    imie=imieTymczasowe;
    nazwisko=nazwiskoTymczasowe;
    numerTelefonu=numerTelefonuTymczasowy;
    email=emailTymczasowy;
    adres=adresTymczasowy;
}

void Adresat::wypiszDaneAdresata() {
    cout<<id<<endl;
    cout<<imie<<endl;
}

int Adresat::pobierzId() {
    return id;
}

int Adresat::pobierzIdUzytkownika() {
    return idUzytkownika;
}

string Adresat::pobierzImie() {
    return imie;
}

string Adresat::pobierzNazwisko() {
    return nazwisko;
}

string Adresat::pobierzNumerTelefonu() {
    return numerTelefonu;
}

string Adresat::pobierzEmail() {
    return email;
}

string Adresat::pobierzAdres() {
    return adres;
}

void Adresat::ustawId(int idDoUstawienia){
    id=idDoUstawienia;
}

void Adresat::ustawIdUzytkownika(int idUzytkownikaDoUstawienia){
    idUzytkownika=idUzytkownikaDoUstawienia;
}

void Adresat::ustawImie(string imieDoUstawienia){
    imie=imieDoUstawienia;
}

void Adresat::ustawNazwisko(string nazwiskoDoUstawienia){
    nazwisko=nazwiskoDoUstawienia;
}

void Adresat::ustawNumerTelefonu(string numerTelefonuDoUstawienia){
    numerTelefonu=numerTelefonuDoUstawienia;
}

void Adresat::ustawEmail(string emailDoUstawienia){
    email=emailDoUstawienia;
}

void Adresat::ustawAdres(string adresDoUstawienia){
    adres=adresDoUstawienia;
}
