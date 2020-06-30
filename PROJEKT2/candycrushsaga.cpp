#include "candycrushsaga.h"

ElementSceny::ElementSceny()
{

}

Cukierek::Cukierek(int x,int y)
{
    if (!cukierek.loadFromFile("grafika/cukierki.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    typ=rand()%7;
    setTexture(cukierek);
    setTextureRect(IntRect(typ*49,0,49,49));
    setPosition(x,y);
    jest_klikniety=false;
}
//152x104 poczatek pola
void Cukierek::zamiana()
{

}

bool Cukierek::match3(Cukierek* &c1, Cukierek* &c2)
{
    auto pos=getPosition();
    auto pos1=c1->getPosition();
    auto pos2=c2->getPosition();
    if((typ==c1->typ&&typ==c2->typ&&pos.x==pos1.x&&pos.x==pos2.x)||
           (typ==c1->typ&&typ==c2->typ&&pos.y==pos1.y&&pos.y==pos2.y)){
        return 1;
    }
    else return 0;
}

bool Cukierek::match4(Cukierek *&c1, Cukierek *&c2, Cukierek *&c3)
{
    auto pos=getPosition();
    auto pos1=c1->getPosition();
    auto pos2=c2->getPosition();
    auto pos3=c2->getPosition();
    if((typ==c1->typ&&typ==c2->typ&&typ==c3->typ&&pos.x==pos1.x&&pos.x==pos2.x&&pos.x==pos3.x)||
       (typ==c1->typ&&typ==c2->typ&&typ==c3->typ&&pos.y==pos1.y&&pos.y==pos2.y&&pos.y==pos3.y)){
        return 1;
    }
    else return 0;
}

bool Cukierek::match5(Cukierek *&c1, Cukierek *&c2, Cukierek *&c3, Cukierek *&c4)
{
    auto pos=getPosition();
    auto pos1=c1->getPosition();
    auto pos2=c2->getPosition();
    auto pos3=c2->getPosition();
    auto pos4=c2->getPosition();
    if((typ==c1->typ&&typ==c2->typ&&typ==c3->typ&&typ==c4->typ&&pos.x==pos1.x&&pos.x==pos2.x&&pos.x==pos3.x&&pos.x==pos4.x)||
       (typ==c1->typ&&typ==c2->typ&&typ==c3->typ&&typ==c4->typ&&pos.y==pos1.y&&pos.y==pos2.y&&pos.y==pos3.y&&pos.y==pos4.y)){
        return 1;
    }
    else return 0;
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

//Vector2i Cukierek::Czy_obok(const Vector2i mouse_position)
//{
//    FloatRect bounds = getGlobalBounds();
//    if(mouse_position.x >= bounds.left &&
//       mouse_position.x <= bounds.left+bounds.width &&
//       mouse_position.y >= bounds.top &&
//       mouse_position.y <= bounds.top+bounds.height
//            ){
//        auto pos=getPosition();
//                return pos;
//    }
//    else return false;

//}



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
    if (!plansza.loadFromFile("grafika/tlo2.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    setTexture(plansza);
}

Znacznik::Znacznik(int x, int y)
{
    if (!znacznik.loadFromFile("grafika/kursor.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    setTexture(znacznik);
    setPosition(x,y);
}
