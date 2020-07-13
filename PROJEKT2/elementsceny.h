#ifndef ELEMENTSCENY_H
#define ELEMENTSCENY_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;
using namespace sf;
class NajlepszyWynik;
class Cukierek;
class ElementSceny: public Sprite{
public:
    ElementSceny();
    bool zaznacz(const Vector2i mouse_position);
    int punkty;
    bool czy_zmiana_wyniku;
    string porownanie(const int &akt, string &naj, NajlepszyWynik &najlepszy, vector <NajlepszyWynik*> &najlepsze);
    bool match(Cukierek* &c1, Cukierek* &c2, Cukierek *&c3, Cukierek *&c4, Cukierek *&c5,int ile);
};

#endif // ELEMENTSCENY_H
