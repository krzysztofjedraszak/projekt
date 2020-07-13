#include "elementsceny.h"
#include "najlepszy_wynik.h"
#include "cukierek.h"


ElementSceny::ElementSceny()
{
    punkty=0;
    czy_zmiana_wyniku=false;
}

bool ElementSceny::zaznacz(const Vector2i mouse_position)
{

        FloatRect bounds = getGlobalBounds();
        if(mouse_position.x >= bounds.left &&
           mouse_position.x <= bounds.left+bounds.width &&
           mouse_position.y >= bounds.top &&
           mouse_position.y <= bounds.top+bounds.height
                ){
            return true;
        }
        else return false;
}

string ElementSceny::porownanie(const int &akt, string &naj, NajlepszyWynik &najlepszy,vector <NajlepszyWynik*> &najlepsze)
{
    auto najint=stoi(naj);
    if(akt>najint){
        najint=akt;
        stringstream ss;
        ss<<najint;
        string str=ss.str();
        najlepszy.wyswietl(str,najlepsze);
        return str;
    }
    else return naj;
}

bool ElementSceny::match(Cukierek *&c1, Cukierek *&c2, Cukierek *&c3, Cukierek *&c4, Cukierek *&c5,int ile)
{
    if(ile==5){
        auto pos=c5->getPosition();
        auto pos1=c1->getPosition();
        auto pos2=c2->getPosition();
        auto pos3=c3->getPosition();
        auto pos4=c4->getPosition();
        if((c5->typ==c1->typ&&c5->typ==c2->typ&&c5->typ==c3->typ&&c5->typ==c4->typ&&pos.x==pos1.x&&pos.x==pos2.x&&pos.x==pos3.x&&pos.x==pos4.x)||
           (c5->typ==c1->typ&&c5->typ==c2->typ&&c5->typ==c3->typ&&c5->typ==c4->typ&&pos.y==pos1.y&&pos.y==pos2.y&&pos.y==pos3.y&&pos.y==pos4.y)){
            return 1;
        }
        else return 0;
    }
    if(ile==4){
    auto pos=c4->getPosition();
    auto pos1=c1->getPosition();
    auto pos2=c2->getPosition();
    auto pos3=c3->getPosition();
    if((c4->typ==c1->typ&&c4->typ==c2->typ&&c4->typ==c3->typ&&pos.x==pos1.x&&pos.x==pos2.x&&pos.x==pos3.x)||
       (c4->typ==c1->typ&&c4->typ==c2->typ&&c4->typ==c3->typ&&pos.y==pos1.y&&pos.y==pos2.y&&pos.y==pos3.y)){
        return 1;
    }
    else return 0;
    }

    if(ile==3){
    auto pos=c3->getPosition();
    auto pos1=c1->getPosition();
    auto pos2=c2->getPosition();
    if((c3->typ==c1->typ&&c3->typ==c2->typ&&pos.x==pos1.x&&pos.x==pos2.x)||
           (c3->typ==c1->typ&&c3->typ==c2->typ&&pos.y==pos1.y&&pos.y==pos2.y)){
        return 1;
    }
    else return 0;
    }
}










