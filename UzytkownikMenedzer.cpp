#include "UzytkownikMenedzer.h"

UzytkownikMenedzer::UzytkownikMenedzer(string nazwaPlikuZUzytkownikami):plikZUzytkownikami(nazwaPlikuZUzytkownikami) {
    uzytkownicy=plikZUzytkownikami.wczytajUzytkownikowZPliku();
    idZalogowanegoUzytkownika=0;
    wyswietlMenuNiezalogowanegoUzytkownika();
};

void UzytkownikMenedzer::wyswietlMenuNiezalogowanegoUzytkownika() {
    char wybor= {0};
    while (true) {
        if (idZalogowanegoUzytkownika == 0) {
            wybor = wybierzOpcjeZMenuGlownego();

            switch (wybor) {
            case '1': {
                rejestracjaUzytkownika();
            }
            break;
            case '2': {
                idZalogowanegoUzytkownika=logowanieUzytkownika();
                AdresatMenedzer adresatMenedzer(idZalogowanegoUzytkownika);
            }
            break;
            case '9': {
                exit(0);
            }
            break;
            default: {
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
            }
            break;
            }
        }
    }
}

char UzytkownikMenedzer::wybierzOpcjeZMenuGlownego() {
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = wczytajZnak();

    return wybor;
}

char UzytkownikMenedzer::wczytajZnak() {
    string wejscie = "";
    char znak  = {0};
    cin.sync();
    while (true) {
        getline(cin, wejscie);

        if (wejscie.length() == 1) {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return znak;
}

int UzytkownikMenedzer::logowanieUzytkownika() {
    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = wczytajLinie();

    for(int i=0; i<uzytkownicy.size(); i++) {
        if (uzytkownicy[i].pobierzLogin()==login) {
            for(int iloscProb=3; iloscProb>0; iloscProb--) {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = wczytajLinie();
                if(uzytkownicy[i].pobierzHaslo()==haslo) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return uzytkownicy[i].pobierzId();
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

string UzytkownikMenedzer::wczytajLinie() {
    cin.sync();
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}

void UzytkownikMenedzer::rejestracjaUzytkownika() {
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);

    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout <<"Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika() {
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());
    string login;
    do {
        cout <<"Podaj login: ";
        cin>>login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);
    string haslo;
    cout << "Podaj haslo: ";
    cin>>haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}


int UzytkownikMenedzer::pobierzIdNowegoUzytkownika() {
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login) {
    for(int i=0; i<uzytkownicy.size(); i++) {
        if(uzytkownicy[i].pobierzLogin()==login) {
            cout<<endl<<"Istnieje uzytkownik o takim loginie."<<endl;
            return true;
        } else {
            i++;
        }
    }
    return false;
}

void UzytkownikMenedzer::wypiszWszystkichUzytkownikow() {
    for(int i=0; i<uzytkownicy.size(); i++) {
        cout<<uzytkownicy[i].pobierzId()<<endl;
        cout<<uzytkownicy[i].pobierzLogin()<<endl;
        cout<<uzytkownicy[i].pobierzHaslo()<<endl;
    }
}

int UzytkownikMenedzer::logowanieUzytkownika() {

    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();

    for(int i=0;i<uzytkownicy.size();i++){
        if(uzytkownicy[i].pobierzLogin()==login){
            for(int iloscProb = 3; iloscProb>0; iloscProb--){
                cout<<"Podaj haslo. Pozostalo prob: "<<iloscProb<<": ";
                haslo=MetodyPomocnicze::wczytajLinie();
                if(uzytkownicy[i].pobierzHaslo()==haslo){
                    cout<<endl<<"Zalogowales sie."<<endl<<endl;
                    system("pause");
                    idZalogowanegoUzytkownika=uzytkownicy[i].pobierzId();
                    return idZalogowanegoUzytkownika;
                }
            }
            cout<<"Wprowadzono 3 razy bledne haslo."<<endl;
            system("pause");
            return 0;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

char UzytkownikMenedzer::wybierzOpcjeZMenuUzytkownika(){
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

bool UzytkownikMenedzer::czyUzytkownikJestZalogowany(){
    if (idZalogowanegoUzytkownika==0){
        return false;
    }else{
        return true;
    }
}

int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika(){
    return idZalogowanegoUzytkownika;
}
