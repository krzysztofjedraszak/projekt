#include "cukierek.h"

Cukierek::Cukierek(int x,int y)
{    
        if (!cukierek.loadFromFile("grafika/cukierki.png")) {
            std::cerr << "Could not load texture" << std::endl;
        }
        typ=rand()%7;
        setTexture(cukierek);
        setTextureRect(IntRect(typ*49,0,49,49));
        setPosition(x,y);
        jest_klikniety=false;

}

int Cukierek::gettyp()
{
    return typ;
}

bool Cukierek::get_jest_klikniety()
{
    return jest_klikniety;
}

bool Cukierek::set_jest_klikniety(bool n)
{
    jest_klikniety=n;
}




