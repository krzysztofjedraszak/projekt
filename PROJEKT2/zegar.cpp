#include "zegar.h"

Zegar::Zegar()
{

}

Zegar::Zegar(int x, int y,int s)
{
    if (!cyfry.loadFromFile("grafika/cyfry.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    setTexture(cyfry);
    setTextureRect(IntRect(s*15,0,15,24));
    setPosition(x,y);
}

