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
        if((c5->gettyp()==c1->gettyp()&&c5->gettyp()==c2->gettyp()&&c5->gettyp()==c3->gettyp()&&c5->gettyp()==c4->gettyp()&&pos.x==pos1.x&&pos.x==pos2.x&&pos.x==pos3.x&&pos.x==pos4.x)||
           (c5->gettyp()==c1->gettyp()&&c5->gettyp()==c2->gettyp()&&c5->gettyp()==c3->gettyp()&&c5->gettyp()==c4->gettyp()&&pos.y==pos1.y&&pos.y==pos2.y&&pos.y==pos3.y&&pos.y==pos4.y)){
            return 1;
        }
        else return 0;
    }
    if(ile==4){
    auto pos=c4->getPosition();
    auto pos1=c1->getPosition();
    auto pos2=c2->getPosition();
    auto pos3=c3->getPosition();
    if((c4->gettyp()==c1->gettyp()&&c4->gettyp()==c2->gettyp()&&c4->gettyp()==c3->gettyp()&&pos.x==pos1.x&&pos.x==pos2.x&&pos.x==pos3.x)||
       (c4->gettyp()==c1->gettyp()&&c4->gettyp()==c2->gettyp()&&c4->gettyp()==c3->gettyp()&&pos.y==pos1.y&&pos.y==pos2.y&&pos.y==pos3.y)){
        return 1;
    }
    else return 0;
    }

    if(ile==3){
    auto pos=c3->getPosition();
    auto pos1=c1->getPosition();
    auto pos2=c2->getPosition();
    if((c3->gettyp()==c1->gettyp()&&c3->gettyp()==c2->gettyp()&&pos.x==pos1.x&&pos.x==pos2.x)||
           (c3->gettyp()==c1->gettyp()&&c3->gettyp()==c2->gettyp()&&pos.y==pos1.y&&pos.y==pos2.y)){
        cout<<"jest match 3"<<endl;
        return 1;
    }
    else return 0;
    }
}

void ElementSceny::usun(Cukierek *&c,int val, Cukierek *&c1, int val1, Cukierek *&c2, int val2, Cukierek *&c3, int val3, Cukierek *&c4, int val4, vector<Cukierek *> &elementy, int ile)
{
    if(ile==5){
        auto pos=c->getPosition();
        auto pos1=c1->getPosition();
        auto pos2=c2->getPosition();
        auto pos3=c3->getPosition();
        auto pos4=c4->getPosition();

        delete *(elementy.begin()+val1);
        elementy.erase(elementy.begin()+val1);
        elementy.insert(elementy.begin()+val1,new Cukierek(pos1.x,pos1.y,0));

        delete *(elementy.begin()+val);
        elementy.erase(elementy.begin()+val);
        elementy.insert(elementy.begin()+val,new Cukierek(pos.x,pos.y,0));

        delete *(elementy.begin()+val2);
        elementy.erase(elementy.begin()+val2);
        elementy.insert(elementy.begin()+val2,new Cukierek(pos2.x,pos2.y,0));

        delete *(elementy.begin()+val3);
        elementy.erase(elementy.begin()+val3);
        elementy.insert(elementy.begin()+val3,new Cukierek(pos3.x,pos3.y,0));

        delete *(elementy.begin()+val4);
        elementy.erase(elementy.begin()+val4);
        elementy.insert(elementy.begin()+val4,new Cukierek(pos4.x,pos4.y,0));

        punkty+=50;
        czy_zmiana_wyniku=true;
    }
    if(ile==4){
        auto pos=c->getPosition();
        auto pos1=c1->getPosition();
        auto pos2=c2->getPosition();
        auto pos3=c3->getPosition();

        delete *(elementy.begin()+val1);
        elementy.erase(elementy.begin()+val1);
        elementy.insert(elementy.begin()+val1,new Cukierek(pos1.x,pos1.y,0));

        delete *(elementy.begin()+val);
        elementy.erase(elementy.begin()+val);
        elementy.insert(elementy.begin()+val,new Cukierek(pos.x,pos.y,0));

        delete *(elementy.begin()+val2);
        elementy.erase(elementy.begin()+val2);
        elementy.insert(elementy.begin()+val2,new Cukierek(pos2.x,pos2.y,0));

        delete *(elementy.begin()+val3);
        elementy.erase(elementy.begin()+val3);
        elementy.insert(elementy.begin()+val3,new Cukierek(pos3.x,pos3.y,0));

        punkty+=40;
        czy_zmiana_wyniku=true;
    }
    if(ile==3){
        auto pos=c->getPosition();
        auto pos1=c1->getPosition();
        auto pos2=c2->getPosition();

        delete *(elementy.begin()+val1);
        elementy.erase(elementy.begin()+val1);
        elementy.insert(elementy.begin()+val1,new Cukierek(pos1.x,pos1.y,0));

        delete *(elementy.begin()+val);
        elementy.erase(elementy.begin()+val);
        elementy.insert(elementy.begin()+val,new Cukierek(pos.x,pos.y,0));

        delete *(elementy.begin()+val2);
        elementy.erase(elementy.begin()+val2);
        elementy.insert(elementy.begin()+val2,new Cukierek(pos2.x,pos2.y,0));

        punkty+=30;
        czy_zmiana_wyniku=true;
    }
}

vector<Cukierek *> ElementSceny::nazwa()
{
    for(int j=0;j<10;j++){
        for(int i=0;i<10;i++){
    this->cuksy.emplace_back(new Cukierek(154+i*50,104+j*50,0));
        }}
    return cuksy;
}

bool ElementSceny::get_zmiana()
{
    return czy_zmiana_wyniku;
}

bool ElementSceny::set_zmiana(bool n)
{
    czy_zmiana_wyniku=n;
}

int ElementSceny::get_punkty()
{
    return punkty;
}

int ElementSceny::set_punkty(int pkt)
{
    punkty=pkt;
}










