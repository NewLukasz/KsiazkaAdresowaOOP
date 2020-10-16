#include "Adresat.h"

Adresat::Adresat(int idTymczasowe, int idUzytkownikaTymczasowe, string imieTymczasowe, string nazwiskoTymczasowe, string numerTelefonuTymczasowy, string emailTymczasowy, string adresTymczasowy){
    id=idTymczasowe;
    idUzytkownika=idUzytkownikaTymczasowe;
    imie=imieTymczasowe;
    nazwisko=nazwiskoTymczasowe;
    numerTelefonu=numerTelefonuTymczasowy;
    email=emailTymczasowy;
    adres=adresTymczasowy;
}

void Adresat::wypiszDaneAdresata(){
    cout<<id<<endl;
    cout<<imie<<endl;
}
