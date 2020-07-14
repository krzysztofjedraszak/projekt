#include "cukierek.h"

Cukierek::Cukierek(int x,int y,int z)
{
    if(z==4){
        if (!specjalne.loadFromFile("grafika/specjalne.png")) {
            std::cerr << "Could not load texture" << std::endl;
        }

        setTexture(specjalne);
        setTextureRect(IntRect(196,0,49,49));
        setPosition(x,y);
        jest_klikniety=false;
    }
    else{
    if (!cukierek.loadFromFile("grafika/cukierki.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    typ=rand()%7;
//    gettyp();
    setTexture(cukierek);
    setTextureRect(IntRect(typ*49,0,49,49));
    setPosition(x,y);
    jest_klikniety=false;
    }
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
//Cukierek::Cukierek(int x, int y, int z)
//{
//    if(z==4){
//        if (!specjalne.loadFromFile("grafika/specjalne.png")) {
//            std::cerr << "Could not load texture" << std::endl;
//        }
//        typ=44;
//        setTexture(specjalne);
//        setTextureRect(IntRect(196,0,49,49));
//        setPosition(x,y);
//        jest_klikniety=false;
//    }
//}


//152x104 poczatek pola



