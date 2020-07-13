#include "plansza.h"

Plansza::Plansza()
{
    if (!plansza.loadFromFile("grafika/tlo2.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    setTexture(plansza);
}
