#include "PlikZUzytkownikami.h"

bool PlikZUzytkownikami::czyPlikJestPusty(fstream &plikTekstowy) {
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}

void PlikZUzytkownikami::dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik) {
    fstream plikTekstowy;
    string liniaZDanymiUzytkownika = "";
    plikTekstowy.open(nazwaPlikuZUzytkownikami.c_str(),ios::out|ios::app);
    if (plikTekstowy.good() == true) {
        liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(uzytkownik);

        if (czyPlikJestPusty(plikTekstowy) == true) {
            plikTekstowy << liniaZDanymiUzytkownika;
        } else {
            plikTekstowy << endl << liniaZDanymiUzytkownika ;
        }
    } else
        cout << "Nie udalo sie otworzyc pliku " << nazwaPlikuZUzytkownikami << " i zapisac w nim danych." << endl;
    plikTekstowy.close();
}

string PlikZUzytkownikami::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik) {
    string liniaZDanymiUzytkownika = "";

    liniaZDanymiUzytkownika += MetodyPomocnicze::konwerjsaIntNaString(uzytkownik.pobierzId())+ '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzLogin() + '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzHaslo() + '|';

    return liniaZDanymiUzytkownika;
}

vector <Uzytkownik> PlikZUzytkownikami::wczytajUzytkownikowZPliku() {
    fstream plikTekstowy;
    vector <Uzytkownik> uzytkownicy;
    plikTekstowy.open(nazwaPlikuZUzytkownikami.c_str(), ios::in);
    if (plikTekstowy.good() == true) {
        while (getline(plikTekstowy, daneJednegoUzytkownikaOddzielonePionowymiKreskami)) {
            uzytkownik = pobierzDaneUzytkownika();
            uzytkownicy.push_back(uzytkownik);
        }
    }
    plikTekstowy.close();
    return uzytkownicy;
}

Uzytkownik PlikZUzytkownikami::pobierzDaneUzytkownika() {
    string pojedynczaDanaUzytkownika = "";
    int numerPojedynczejDanejUzytkownika = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneJednegoUzytkownikaOddzielonePionowymiKreskami.length(); pozycjaZnaku++) {
        if (daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku] != '|') {
            pojedynczaDanaUzytkownika += daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku];
        } else {
            switch(numerPojedynczejDanejUzytkownika) {
            case 1:
                uzytkownik.ustawId(atoi(pojedynczaDanaUzytkownika.c_str()));
                break;
            case 2:
                uzytkownik.ustawLogin(pojedynczaDanaUzytkownika);
                break;
            case 3:
                uzytkownik.ustawHaslo(pojedynczaDanaUzytkownika);
                break;
            }
            pojedynczaDanaUzytkownika = "";
            numerPojedynczejDanejUzytkownika++;
        }
    }
    return uzytkownik;
}

void PlikZUzytkownikami::zmianaHasloUzytkownika(int idZalogowaneUzytkownika, Uzytkownik uzytkownik) {
    fstream plikTekstowy, plikTekstowyTymczasowy;

    plikTekstowy.open(nazwaPlikuZUzytkownikami.c_str(), ios::in);
    plikTekstowyTymczasowy.open("UzytkownicyTymczasowy.txt", ios::out | ios::app);

    string liniaZDanymiUzytkownika="";

    if (plikTekstowy.good() == true) {
        while (getline(plikTekstowy, liniaZDanymiUzytkownika)) {
            if(idZalogowaneUzytkownika!=pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(liniaZDanymiUzytkownika)) {
                if (czyPlikJestPusty(plikTekstowyTymczasowy) == true) {
                    plikTekstowyTymczasowy << liniaZDanymiUzytkownika;
                } else {
                    plikTekstowyTymczasowy << endl << liniaZDanymiUzytkownika ;
                }
            } else if(idZalogowaneUzytkownika==pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(liniaZDanymiUzytkownika)) {
                liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(uzytkownik);


                if (czyPlikJestPusty(plikTekstowyTymczasowy) == true) {
                    plikTekstowyTymczasowy << liniaZDanymiUzytkownika;
                } else {
                    plikTekstowyTymczasowy << endl << liniaZDanymiUzytkownika ;
                }
            }
        }
    } else {
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;
    }

    plikTekstowy.close();
    plikTekstowyTymczasowy.close();

    remove(nazwaPlikuZUzytkownikami.c_str());
    rename("UzytkownicyTymczasowy.txt",nazwaPlikuZUzytkownikami.c_str());
}


int PlikZUzytkownikami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoUzytkownikaOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdUzytkownika = 0;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(pobierzLiczbe(daneJednegoUzytkownikaOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));
    return idUzytkownika;
}

string PlikZUzytkownikami::pobierzLiczbe(string tekst, int pozycjaZnaku) {
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true) {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}
