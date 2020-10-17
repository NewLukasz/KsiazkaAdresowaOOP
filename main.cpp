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
            //int idOstatniegoAdresata=ksiazkaAdresowa.przeslijIdOstatniegoAdresata();
            switch (wybor) {
            case '1':
                ksiazkaAdresowa.dodajAdresata();
                break;
            case '2':
//                wyszukajAdresatowPoImieniu(adresaci);
                break;
            case '3':
//                wyszukajAdresatowPoNazwisku(adresaci);
                break;
            case '4':
                ksiazkaAdresowa.wypiszDaneWszytkichAdresatow();
//                wyswietlWszystkichAdresatow(adresaci);
                break;
            case '5':
//                idUsunietegoAdresata = usunAdresata(adresaci);
//                idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                break;
            case '6':
//                edytujAdresata(adresaci);
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
