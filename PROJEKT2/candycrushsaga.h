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
    bool zaznacz(const Vector2i mouse_position);
    int punkty;
    bool czy_zmiana_wyniku;
};

class Cukierek: public ElementSceny{
    Texture cukierek;

public:
    Cukierek(int x, int y);
    void zamiana();
    int typ;
    bool jest_klikniety;
    bool match3(Cukierek *&c1, Cukierek *&c2);
    bool match4(Cukierek *&c1, Cukierek *&c2,Cukierek *&c3);
    bool match5(Cukierek *&c1, Cukierek *&c2,Cukierek *&c3,Cukierek *&c4);
    void usun3(int val, Cukierek *&c1, int val1, Cukierek *&c2, int val2, vector <Cukierek*> elementy);
    void usun4(int val, Cukierek *&c1, int val1, Cukierek *&c2, int val2, Cukierek *&c3, int val3, vector <Cukierek*> elementy);
    void usun5(int val, Cukierek *&c1, int val1, Cukierek *&c2, int val2,Cukierek *&c3,int val3,Cukierek *&c4,int val4, vector<Cukierek *> elementy);
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
