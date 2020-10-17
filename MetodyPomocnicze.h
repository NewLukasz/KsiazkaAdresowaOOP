#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

class MetodyPomocnicze{

public:
     static string konwerjsaIntNaString(int liczba);
     static char wczytajZnak();
     static string wczytajLinie();
     static int konwersjaStringNaInt(string liczba);
};
#endif
