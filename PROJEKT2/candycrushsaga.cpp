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

bool Cukierek::match(Cukierek* &c1, Cukierek* &c2)
{
    if(typ==c1->typ&&typ==c2->typ){
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
