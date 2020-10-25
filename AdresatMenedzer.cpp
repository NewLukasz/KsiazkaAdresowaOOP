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
    return plikZAdresatami.pobierzIdOstatniegoAdresata();

}

void AdresatMenedzer::wyswietlKontaktyWyszukanePoImieniu() {
    system("cls");
    cout<<"Podaj imie: ";
    string wyszukiwaneImie=MetodyPomocnicze::wczytajLinie();
    for(int i=0; i<adresaci.size(); i++) {
        if(wyszukiwaneImie==adresaci[i].pobierzImie()) {
            adresaci[i].wypiszDaneAdresata();
        }
    }
    system("pause");
}

void AdresatMenedzer::wyswietlKontaktyWyszukanePoNazwisku() {
    system("cls");
    cout<<"Podaj nazwisko: ";
    string wyszukiwaneNazwisko=MetodyPomocnicze::wczytajLinie();
    for(int i=0; i<adresaci.size(); i++) {
        if(wyszukiwaneNazwisko==adresaci[i].pobierzNazwisko()) {
            adresaci[i].wypiszDaneAdresata();
        }
    }
    system("pause");
}

void AdresatMenedzer::usunWybranegoAdresata() {
    int iDAdresataDoUsuniecia=0;
    char znak='a';
    system("cls");
    wypiszWszystkichAdresatow();
    cout<<endl<<"Podaj ID adresata ktorego chcesz usunac: ";
    cin>>iDAdresataDoUsuniecia;
    for(int i=0; i<adresaci.size(); i++) {
        if(adresaci[i].pobierzId()==iDAdresataDoUsuniecia) {
            cout<<endl<<"Czy na pewno chcesz usunac adresata? Jezeli tak wcisnik t."<<endl;
            znak=MetodyPomocnicze::wczytajZnak();
            if(znak=='t') {
                plikZAdresatami.usuwanieAdresataZPliku(iDAdresataDoUsuniecia);
                break;
            }
        } else if(i==adresaci.size()-1) {
            cout<<"Adresat z id wynoszacym "<<iDAdresataDoUsuniecia<<" nie istnieje"<<endl;
            system("pause");
        }
    }
}

void AdresatMenedzer::edytujAdresata() {
    system("cls");
    wypiszWszystkichAdresatow();
    int idAdresataDoModyfikacji;
    cout<<endl<<"Podaj ID adresata, ktorego chcesz zmodyfikowac: ";
    cin>>idAdresataDoModyfikacji;
    for(int i=0; i<adresaci.size(); i++) {
        if(idAdresataDoModyfikacji==adresaci[i].pobierzId()) {
            system("cls");
            cout<<"Modyfikowany kontakt to: "<<endl;
            adresaci[i].wypiszDaneAdresata();

            system("cls");
            cout<<"Podaj numer pola ktore ma zostac zmodyfikowane."<<endl;
            cout<<"1. Imie"<<endl<<"2. Nazwisko"<<endl<<"3. Numer telefonu"<<endl<<"4. Email"<<endl<<"5. Adres"<<endl;
            cout<<"Pole do modyfikacji: ";
            char wybor;
            cin>>wybor;
            switch (wybor) {
            case '1': {
                cout<<"Podaj nowa wartosc dla pola imie: ";
                string noweImie=MetodyPomocnicze::wczytajLinie();
                adresaci[i].ustawImie(noweImie);
                plikZAdresatami.modyfikacjaAdresataWPliku(idAdresataDoModyfikacji, adresaci[i]);
                break;
            }
            case '2': {
                cout<<"Podaj nowa wartosc dla pola nazwisko: ";
                string noweNazwisko=MetodyPomocnicze::wczytajLinie();
                adresaci[i].ustawNazwisko(noweNazwisko);
                plikZAdresatami.modyfikacjaAdresataWPliku(idAdresataDoModyfikacji, adresaci[i]);
                break;
            }

            case '3': {
                cout<<"Podaj nowa wartosc dla pola numer telefonu: ";
                string nowyNumer=MetodyPomocnicze::wczytajLinie();
                adresaci[i].ustawNumerTelefonu(nowyNumer);
                plikZAdresatami.modyfikacjaAdresataWPliku(idAdresataDoModyfikacji, adresaci[i]);
                break;
            }

            case '4': {
                cout<<"Podaj nowa wartosc dla pola email: ";
                string nowyEmail=MetodyPomocnicze::wczytajLinie();
                adresaci[i].ustawEmail(nowyEmail);
                plikZAdresatami.modyfikacjaAdresataWPliku(idAdresataDoModyfikacji, adresaci[i]);
                break;
            }
            case '5': {
                cout<<"Podaj nowa wartosc dla pola adres: ";
                string nowyAdres=MetodyPomocnicze::wczytajLinie();
                adresaci[i].ustawAdres(nowyAdres);
                plikZAdresatami.modyfikacjaAdresataWPliku(idAdresataDoModyfikacji, adresaci[i]);
                break;
            }
            default: {
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
            }
        } else if(i==adresaci.size()-1) {
            cout<<"Brak adresata o taki id!"<<endl;
            system("pause");
            break;
        }
    }
    system("pause");
}


