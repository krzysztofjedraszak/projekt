#ifndef ELEMENTSCENY_H
#define ELEMENTSCENY_H
#include "abstract.h"

class Znacznik;
class NajlepszyWynik;
class Cukierek;
class AktualnyWynik;
class Zegar;
class Plansza;
class ElementSceny: public Abstract{
    vector <Cukierek*> cuksy;
    vector <Znacznik*> znaczniki;
    vector <AktualnyWynik*> wyniki;
//    vector <NajlepszyWynik*> najlepsze;
    vector <NajlepszyWynik*> best;
    vector <Zegar*> zegarki;
    int punkty;
    bool czy_zmiana_wyniku;
    int klik;
    int x,y,x0,y0;
    Cukierek* pierwszy_el;
    Cukierek* drugi_el;
    float czas=120;
public:
    ElementSceny();
    string porownanie(const int &akt,const string &naj, ElementSceny &scena);
    bool match(Cukierek* &c1, Cukierek* &c2, Cukierek *&c3, Cukierek *&c4, Cukierek *&c5,int ile);
    void usun(Cukierek *&c, int val, Cukierek *&c1, int val1, Cukierek *&c2, int val2, Cukierek *&c3, int val3, Cukierek *&c4, int val4, int ile);
    vector<Cukierek*>stworz_cuksy();
    vector<Cukierek*>pokaz_cuksy();
    vector<Znacznik*>pokaz_znacznik();
    vector<Zegar*>pokaz_zegarki();
    vector<AktualnyWynik*>pokaz_aktualne();
    vector<NajlepszyWynik*>pokaz_najlepsze();
    bool get_zmiana();
    bool set_zmiana(bool n);
    int get_punkty();
    int set_punkty(int pkt);
    void zrob(const Vector2i mouse_pos);
    void match_i_usun();
    void wyswietl_naj_wynik(string str);
    string wczytaj_naj_wynik();
    void zapisz_naj_wynik(string wynik);
    void odliczanie(Clock &clk);
    void wyswietl_aktualny(const int &punkty);
    void jesli_zmiana_wyniku(ElementSceny &scena);
    void pokaz_wszystko(RenderWindow &window, ElementSceny scena, Plansza p1);
};

#endif // ELEMENTSCENY_H
