#ifndef CUKIEREK_H
#define CUKIEREK_H

#include "elementsceny.h"

class Cukierek: public ElementSceny{
    Texture cukierek;
    Texture specjalne;
public:
//    Cukierek(int x,int y,int z);
    Cukierek(int x, int y, int z);
    void zamiana();
    int typ;
    bool jest_klikniety;
    bool match3(Cukierek *&c1, Cukierek *&c2);
    bool match4(Cukierek *&c1, Cukierek *&c2,Cukierek *&c3);
    bool match5(Cukierek *&c1, Cukierek *&c2,Cukierek *&c3,Cukierek *&c4);
    void usun3(int val, Cukierek *&c1, int val1, Cukierek *&c2, int val2, vector<Cukierek *> &elementy);
    void usun4(int val, Cukierek *&c1, int val1, Cukierek *&c2, int val2, Cukierek *&c3, int val3, vector <Cukierek*> &elementy);
    void usun5(int val, Cukierek *&c1, int val1, Cukierek *&c2, int val2, Cukierek *&c3,int val3, Cukierek *&c4,int val4, vector<Cukierek *> &elementy);
};

#endif // CUKIEREK_H
