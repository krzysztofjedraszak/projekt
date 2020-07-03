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
class ElementSceny: public Sprite{
public:
    ElementSceny();
    bool zaznacz(const Vector2i mouse_position);
    int punkty;
    bool czy_zmiana_wyniku;
    string porownanie(const int &akt, string &naj, NajlepszyWynik &najlepszy, vector <NajlepszyWynik*> &najlepsze);
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
    void usun3(int val, Cukierek *&c1, int val1, Cukierek *&c2, int val2, vector<Cukierek *> &elementy);
    void usun4(int val, Cukierek *&c1, int val1, Cukierek *&c2, int val2, Cukierek *&c3, int val3, vector <Cukierek*> &elementy);
    void usun5(int val, Cukierek *&c1, int val1, Cukierek *&c2, int val2, Cukierek *&c3,int val3, Cukierek *&c4,int val4, vector<Cukierek *> &elementy);
};
class NajlepszyWynik: public ElementSceny{
    Texture cyfry;
public:
    NajlepszyWynik();
    NajlepszyWynik(const int x,const int y,const int s);
    void wyswietl(string str, vector<NajlepszyWynik *> &najlepsze);
    string wczytaj();
    void zapisz(string wynik);
};
class AktualnyWynik: public ElementSceny{
    Texture cyfry;
public:
    AktualnyWynik();
    AktualnyWynik(const int x,const int y,const int s);
    void wyswietl(const int &punkty, vector<AktualnyWynik *> &wyniki);
};
class Plansza: public ElementSceny{
    Texture plansza;
public:
    Plansza();
};
class Zegar: public ElementSceny{
    Texture cyfry;
public:
    Zegar();
    Zegar(int x, int y,int s);
    void odliczanie(Clock &clk, vector<Zegar *> &zegary);
    float czas=120;
};
class Znacznik: public ElementSceny{
    Texture znacznik;
public:
    Znacznik(int x, int y);
};

#endif // ELEMENTSCENY_H
