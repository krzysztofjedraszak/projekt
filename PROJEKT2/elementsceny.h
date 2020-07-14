#ifndef ELEMENTSCENY_H
#define ELEMENTSCENY_H
#include "abstract.h"

class Znacznik;
class NajlepszyWynik;
class Cukierek;
class ElementSceny: public Abstract{
    vector<Cukierek*> cuksy;
    vector<Znacznik*> znaczniki;
    int punkty;
    bool czy_zmiana_wyniku;
    int klik;
    int x,y,x0,y0;
    Cukierek* pierwszy_el;
    Cukierek* drugi_el;
public:
    ElementSceny();
    bool zaznacz(const Vector2i mouse_position);
    string porownanie(const int &akt, string &naj, NajlepszyWynik &najlepszy, vector <NajlepszyWynik*> &najlepsze);
    bool match(Cukierek* &c1, Cukierek* &c2, Cukierek *&c3, Cukierek *&c4, Cukierek *&c5,int ile);
    void usun(Cukierek *&c, int val, Cukierek *&c1, int val1, Cukierek *&c2, int val2, Cukierek *&c3, int val3, Cukierek *&c4, int val4, vector<Cukierek *> &elementy, int ile);
    vector<Cukierek*>stworz_cuksy();
    vector<Znacznik*>stworz_znacznik();
    bool get_zmiana();
    bool set_zmiana(bool n);
    int get_punkty();
    int set_punkty(int pkt);
    void zrob(const Vector2i mouse_pos);
    vector<Cukierek*>pokaz_cuksy();
    vector<Znacznik*>pokaz_znacznik();
    void match_i_usun();
};

#endif // ELEMENTSCENY_H
