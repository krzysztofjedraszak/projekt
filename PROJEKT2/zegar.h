#ifndef ZEGAR_H
#define ZEGAR_H
#include "abstract.h"

class Zegar: public Abstract{
    Texture cyfry;
    float czas=120;
public:
    Zegar();
    Zegar(int x, int y,int s);
};

#endif // ZEGAR_H
