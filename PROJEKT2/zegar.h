#ifndef ZEGAR_H
#define ZEGAR_H

#include "elementsceny.h"

class Zegar: public ElementSceny{
    Texture cyfry;
public:
    Zegar();
    Zegar(int x, int y,int s);
    void odliczanie(Clock &clk, vector<Zegar *> &zegary);
    float czas=120;
};

#endif // ZEGAR_H
