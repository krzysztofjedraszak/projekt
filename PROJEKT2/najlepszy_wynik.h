#ifndef NAJLEPSZY_WYNIK_H
#define NAJLEPSZY_WYNIK_H
#include "abstract.h"

class NajlepszyWynik: public Abstract{
    Texture cyfry;
public:
    NajlepszyWynik();
    NajlepszyWynik(const int x,const int y,const int s);
    void wyswietl(string str, vector<NajlepszyWynik *> &najlepsze);
    string wczytaj();
    void zapisz(string wynik);
};

#endif // NAJLEPSZY_WYNIK_H
