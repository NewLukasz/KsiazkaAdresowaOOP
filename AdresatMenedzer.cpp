#include "AdresatMenedzer.h"

void AdresatMenedzer::dodajAdresata() {
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
    Adresat adresat(przeslijIdOstatniegoAdresata()+1,ID_ZALOGOWANEGO_UZYTKOWNIKA,imie,nazwisko,numerTelefonu,email,adres);

    plikZAdresatami.dopiszAdrestaDoPliku(adresat);

    adresaci.push_back(adresat);

}

void AdresatMenedzer::wypiszWszystkichAdresatow() {
    if(adresaci.size()==0) {
        cout<<"Brak adresatow to wyswietlenia"<<endl;
        system("pause");
    } else {
        for(int i=0; i<adresaci.size(); i++) {
            adresaci[i].wypiszDaneAdresata();
        }
        system("pause");
    }
}

int AdresatMenedzer::przeslijIdOstatniegoAdresata() {
    if(adresaci.size()==0) {
        return plikZAdresatami.pobierzIdOstatniegoAdresata();
    } else {
        return (adresaci.back()).pobierzId();
    }
}

void AdresatMenedzer::wyswietlKontaktyWyszukanePoImieniu(){
    system("cls");
    cout<<"Podaj imie: ";
    string wyszukiwaneImie=MetodyPomocnicze::wczytajLinie();
    for(int i=0;i<adresaci.size();i++){
        if(wyszukiwaneImie==adresaci[i].pobierzImie()){
            adresaci[i].wypiszDaneAdresata();
        }
    }
    system("pause");
}

void AdresatMenedzer::wyswietlKontaktyWyszukanePoNazwisku(){
    system("cls");
    cout<<"Podaj nazwisko: ";
    string wyszukiwaneNazwisko=MetodyPomocnicze::wczytajLinie();
    for(int i=0;i<adresaci.size();i++){
        if(wyszukiwaneNazwisko==adresaci[i].pobierzNazwisko()){
            adresaci[i].wypiszDaneAdresata();
        }
    }
    system("pause");
}
