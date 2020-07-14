#ifndef AKTUALNY_WYNIK_H
#define AKTUALNY_WYNIK_H
#include "abstract.h"

class AktualnyWynik: public Abstract{
    Texture cyfry;
public:
    AktualnyWynik();
    AktualnyWynik(const int x,const int y,const int s);
    void wyswietl(const int &punkty, vector<AktualnyWynik *> &wyniki);
};

#endif // AKTUALNY_WYNIK_H
