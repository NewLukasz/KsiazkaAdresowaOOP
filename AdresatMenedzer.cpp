#include "AdresatMenedzer.h"

void AdresatMenedzer::dodajAdresata(){
    cout<<endl<<"Podaj imie: ";
    string imie=MetodyPomocnicze::wczytajLinie();
    cout<<"Podaj nazwisko: ";
    string nazwisko=MetodyPomocnicze::wczytajLinie();
    cout<<"Podaj numer telefonu: ";
    string numerTelefonu=MetodyPomocnicze::wczytajLinie();
    cout<<"Podaj email: ";
    string email=MetodyPomocnicze::wczytajLinie();
    cout<<"Podaj adres: ";
    string adres=MetodyPomocnicze::wczytajLinie();
    Adresat adresat(1,1,imie,nazwisko,numerTelefonu,email,adres);
    adresaci.push_back(adresat);
}

void AdresatMenedzer::wypiszWszystkichAdresatow(){
    for(int i=0;i<adresaci.size();i++){
        adresaci[i].wypiszDaneAdresata();
    }
    system("pause");
}


