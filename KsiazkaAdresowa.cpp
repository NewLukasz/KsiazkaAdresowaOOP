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

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika(){
    uzytkownikMenedzer.wybierzOpcjeZMenuUzytkownika();
}

int KsiazkaAdresowa::logowanieUzytkownika(){
    uzytkownikMenedzer.logowanieUzytkownika();
}

void KsiazkaAdresowa::dodajAdresata(){
    adresatMenedzer.dodajAdresata();
}

void KsiazkaAdresowa::wypiszDaneWszytkichAdresatow(){
    adresatMenedzer.wypiszWszystkichAdresatow();
}

