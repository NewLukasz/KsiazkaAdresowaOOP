#include <iostream>
#include "KsiazkaAdresowa.h"
using namespace std;

int main() {
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt","Adresaci.txt");
    int idZalogowanegoUzytkownika=0;
    char wybor;

    while (true) {
        if (idZalogowanegoUzytkownika == 0) {
            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuGlownego();
            switch (wybor) {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                idZalogowanegoUzytkownika = ksiazkaAdresowa.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();
            switch (wybor) {
            case '1':
                ksiazkaAdresowa.dodajAdresata();
                ksiazkaAdresowa.zaladujUzytkownikowPonownieZPliku();
                break;
            case '2':
                ksiazkaAdresowa.wyswietlKontaktyWyszukanePoImieniu();
                break;
            case '3':
                ksiazkaAdresowa.wyswietlKontaktyWyszukanePoNazwisku();
                break;
            case '4':
                ksiazkaAdresowa.wypiszDaneWszytkichAdresatow();
                break;
            case '5':
                ksiazkaAdresowa.usunWybranegoAdresata();
                ksiazkaAdresowa.zaladujUzytkownikowPonownieZPliku();
                break;
            case '6':
                ksiazkaAdresowa.edytujAdresata();
                ksiazkaAdresowa.zaladujUzytkownikowPonownieZPliku();
                break;
            case '7':
//                zmianaHaslaZalogowanegoUzytkownika(uzytkownicy, idZalogowanegoUzytkownika);
                break;
            case '8':
                idZalogowanegoUzytkownika = 0;
//                adresaci.clear();
                break;
            }
        }
    }
}
