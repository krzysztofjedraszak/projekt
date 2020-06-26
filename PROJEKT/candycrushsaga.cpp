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

void Cukierek::usun()
{

}

void Cukierek::wyswietl()
{

}

bool ElementSceny::zaznaczcukierek(const Vector2i mouse_position)
{
//    for(unsigned int i=0;i<elementy.size();i++){
//        setTexture(znacznik);
//        auto pos=elementy[i]->getPosition();
//        setPosition(pos.x,pos.y);
//    }
//    for(unsigned int i=0;i<elementy.size();i++){
        FloatRect bounds = /*elementy[i]->*/getGlobalBounds();
        if(mouse_position.x >= bounds.left &&
           mouse_position.x <= bounds.left+bounds.width &&
           mouse_position.y >= bounds.top &&
           mouse_position.y <= bounds.top+bounds.height
                ){
//            setTexture(znacznik);
//            setPosition(bounds.left,bounds.top);
            return true;
        }
        else return false;
}

bool Cukierek::Czy_obok()
{

}



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
