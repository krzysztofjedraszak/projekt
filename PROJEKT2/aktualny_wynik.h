#ifndef AKTUALNY_WYNIK_H
#define AKTUALNY_WYNIK_H

#include "elementsceny.h"

class AktualnyWynik: public ElementSceny{
    Texture cyfry;
public:
    AktualnyWynik();
    AktualnyWynik(const int x,const int y,const int s);
    void wyswietl(const int &punkty, vector<AktualnyWynik *> &wyniki);
};

#endif // AKTUALNY_WYNIK_H
