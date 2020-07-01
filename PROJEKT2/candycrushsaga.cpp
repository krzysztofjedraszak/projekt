#include "candycrushsaga.h"

ElementSceny::ElementSceny()
{
    punkty=0;
    czy_zmiana_wyniku=false;
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

void Cukierek::usun3(int val,Cukierek*& c1,int val1,Cukierek*& c2,int val2,vector <Cukierek*> elementy)
{
    auto pos=getPosition();
    auto pos1=c1->getPosition();
    auto pos2=c2->getPosition();

    delete *(elementy.begin()+val1);
    elementy.erase(elementy.begin()+val1);cout<<elementy.size()<<endl;
    elementy.insert(elementy.begin()+val1,new Cukierek(pos1.x,pos1.y));

    delete *(elementy.begin()+val);
    elementy.erase(elementy.begin()+val);cout<<elementy.size()<<endl;
    elementy.insert(elementy.begin()+val,new Cukierek(pos.x,pos.y));

    delete *(elementy.begin()+val2);
    elementy.erase(elementy.begin()+val2);cout<<elementy.size()<<endl;
    elementy.insert(elementy.begin()+val2,new Cukierek(pos2.x,pos2.y));

    punkty=+30;
}

void Cukierek::usun4(int val, Cukierek *&c1, int val1, Cukierek *&c2, int val2,Cukierek *&c3,int val3, vector<Cukierek *> elementy)
{
    auto pos=getPosition();
    auto pos1=c1->getPosition();
    auto pos2=c2->getPosition();
    auto pos3=c3->getPosition();

    delete *(elementy.begin()+val1);
    elementy.erase(elementy.begin()+val1);cout<<elementy.size()<<endl;
    elementy.insert(elementy.begin()+val1,new Cukierek(pos1.x,pos1.y));

    delete *(elementy.begin()+val);
    elementy.erase(elementy.begin()+val);cout<<elementy.size()<<endl;
    elementy.insert(elementy.begin()+val,new Cukierek(pos.x,pos.y));

    delete *(elementy.begin()+val2);
    elementy.erase(elementy.begin()+val2);cout<<elementy.size()<<endl;
    elementy.insert(elementy.begin()+val2,new Cukierek(pos2.x,pos2.y));

    delete *(elementy.begin()+val3);
    elementy.erase(elementy.begin()+val3);cout<<elementy.size()<<endl;
    elementy.insert(elementy.begin()+val3,new Cukierek(pos3.x,pos3.y));

    punkty=+40;
}

void Cukierek::usun5(int val, Cukierek *&c1, int val1, Cukierek *&c2, int val2,Cukierek *&c3,int val3,Cukierek *&c4,int val4, vector<Cukierek *> elementy)
{
    auto pos=getPosition();
    auto pos1=c1->getPosition();
    auto pos2=c2->getPosition();
    auto pos3=c3->getPosition();
    auto pos4=c4->getPosition();

    delete *(elementy.begin()+val1);
    elementy.erase(elementy.begin()+val1);cout<<elementy.size()<<endl;
    elementy.insert(elementy.begin()+val1,new Cukierek(pos1.x,pos1.y));

    delete *(elementy.begin()+val);
    elementy.erase(elementy.begin()+val);cout<<elementy.size()<<endl;
    elementy.insert(elementy.begin()+val,new Cukierek(pos.x,pos.y));

    delete *(elementy.begin()+val2);
    elementy.erase(elementy.begin()+val2);cout<<elementy.size()<<endl;
    elementy.insert(elementy.begin()+val2,new Cukierek(pos2.x,pos2.y));

    delete *(elementy.begin()+val3);
    elementy.erase(elementy.begin()+val3);cout<<elementy.size()<<endl;
    elementy.insert(elementy.begin()+val3,new Cukierek(pos3.x,pos3.y));

    delete *(elementy.begin()+val4);
    elementy.erase(elementy.begin()+val4);cout<<elementy.size()<<endl;
    elementy.insert(elementy.begin()+val4,new Cukierek(pos4.x,pos4.y));

    punkty=+50;
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
//    if (!cyfry.loadFromFile("grafika/cyfry.png")) {
//        std::cerr << "Could not load texture" << std::endl;
//    }
}

void AktualnyWynik::wyswietl(const int& akt)
{//125
//    int y=0;
//    int cyfra;
//    int x=akt;
//    while (x!=0) {
//        cyfra = x % 10;//5
//        x = x /10;//
//        y = 10*y + cyfra;
//        cout<<y;
//    }
    stringstream ss;
    ss<<akt;
    string str=ss.str();
//    cout<<str[0]<<endl;
//    cout<<str[1]<<endl;
//    cout<<str.length()<<endl;
    for(unsigned int i=0;i<str.length();++i){
        char r=str[i];
        int s=r - '0';
        cout<<s<<endl;
    }

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
