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
    Texture cukierek;

public:
    Cukierek(int x, int y);
    void zamiana();
    void usun();
    void wyswietl();
    int typ;
    bool zaznaczcukierek(const Vector2i mouse_position);
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
class Znacznik: public ElementSceny{
    Texture znacznik;
public:
    Znacznik(int x, int y);
};

#endif // ELEMENTSCENY_H
