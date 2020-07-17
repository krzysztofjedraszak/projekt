#include "najlepszy_wynik.h"

NajlepszyWynik::NajlepszyWynik()
{

}

NajlepszyWynik::NajlepszyWynik(const int x,const int y,const int s)
{
    if (!cyfry.loadFromFile("grafika/cyfry.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    setTexture(cyfry);
    setTextureRect(IntRect(s*15,0,15,24));
    setPosition(x,y);
}

