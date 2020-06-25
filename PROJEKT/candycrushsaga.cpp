#include "candycrushsaga.h"

ElementSceny::ElementSceny()
{

}

Cukierek::Cukierek()
{

}

void Cukierek::zamiana()
{

}

void Cukierek::usun()
{

}

void Cukierek::wyswietl()
{

}

NajlepszyWynik::NajlepszyWynik()
{

}

void NajlepszyWynik::wyswietl()
{

}

void NajlepszyWynik::wczytaj()
{

}

AktualnyWynik::AktualnyWynik()
{

}

void AktualnyWynik::wyswietl()
{

}

Plansza::Plansza()
{
    if (!plansza.loadFromFile("grafika/tlo.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    setTexture(plansza);
}



























