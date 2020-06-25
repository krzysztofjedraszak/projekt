#ifndef ELEMENTSCENY_H
#define ELEMENTSCENY_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class ElementSceny: public Sprite{
public:
    ElementSceny();
};
class Cukierek: public ElementSceny{
    Cukierek();
    void zamiana();
    void usun();
    void wyswietl();
};
class NajlepszyWynik: public ElementSceny{
    NajlepszyWynik();
    void wyswietl();
    void wczytaj();
};
class AktualnyWynik: public ElementSceny{
    AktualnyWynik();
    void wyswietl();
};
class Plansza: public ElementSceny{
    Texture plansza;
public:
    Plansza();
};
class Zegar: public ElementSceny{
    Zegar();
    void odliczanie();
};
#endif // ELEMENTSCENY_H
