#ifndef CUKIEREK_H
#define CUKIEREK_H
#include "abstract.h"

class Cukierek: public Abstract{
    Texture cukierek;
    Texture specjalne;
    int typ;
    bool jest_klikniety;
public:
    Cukierek(int x, int y);
    int gettyp();
    bool get_jest_klikniety();
    bool set_jest_klikniety(bool n);
};

#endif // CUKIEREK_H
