#ifndef ZEGAR_H
#define ZEGAR_H
#include "abstract.h"

class Zegar: public Abstract{
    Texture cyfry;
    float czas=120;
public:
    Zegar();
    Zegar(int x, int y,int s);
    void odliczanie(Clock &clk, vector<Zegar *> &zegary);
};

#endif // ZEGAR_H
