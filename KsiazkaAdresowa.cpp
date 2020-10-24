#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego() {
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika() {
    uzytkownikMenedzer.wybierzOpcjeZMenuUzytkownika();
}

int KsiazkaAdresowa::logowanieUzytkownika() {
    int idZalogowanegoUzytkownika = uzytkownikMenedzer.logowanieUzytkownika();
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
    return idZalogowanegoUzytkownika;
}

void KsiazkaAdresowa::dodajAdresata() {
    adresatMenedzer->dodajAdresata();
}

void KsiazkaAdresowa::wypiszDaneWszytkichAdresatow() {
    adresatMenedzer->wypiszWszystkichAdresatow();
}

void KsiazkaAdresowa::wyswietlKontaktyWyszukanePoImieniu() {
    adresatMenedzer->wyswietlKontaktyWyszukanePoImieniu();
}

void KsiazkaAdresowa::wyswietlKontaktyWyszukanePoNazwisku() {
    adresatMenedzer->wyswietlKontaktyWyszukanePoNazwisku();
}

int KsiazkaAdresowa::przeslijIdOstatniegoAdresata() {
    adresatMenedzer->przeslijIdOstatniegoAdresata();
}

void KsiazkaAdresowa::usunWybranegoAdresata() {
    adresatMenedzer->usunWybranegoAdresata();
}

void KsiazkaAdresowa::zaladujUzytkownikowPonownieZPliku() {
    delete adresatMenedzer;
    adresatMenedzer=NULL;
    adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
}


