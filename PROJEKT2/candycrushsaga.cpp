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
    auto pos3=c3->getPosition();
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
    auto pos3=c3->getPosition();
    auto pos4=c4->getPosition();
    if((typ==c1->typ&&typ==c2->typ&&typ==c3->typ&&typ==c4->typ&&pos.x==pos1.x&&pos.x==pos2.x&&pos.x==pos3.x&&pos.x==pos4.x)||
       (typ==c1->typ&&typ==c2->typ&&typ==c3->typ&&typ==c4->typ&&pos.y==pos1.y&&pos.y==pos2.y&&pos.y==pos3.y&&pos.y==pos4.y)){
        return 1;
    }
    else return 0;
}

void Cukierek::usun3(int val,Cukierek*& c1,int val1,Cukierek*& c2,int val2,vector <Cukierek*> &elementy)
{
    auto pos=getPosition();
    auto pos1=c1->getPosition();
    auto pos2=c2->getPosition();

    delete *(elementy.begin()+val1);
    elementy.erase(elementy.begin()+val1);
    elementy.insert(elementy.begin()+val1,new Cukierek(pos1.x,pos1.y));

    delete *(elementy.begin()+val);
    elementy.erase(elementy.begin()+val);
    elementy.insert(elementy.begin()+val,new Cukierek(pos.x,pos.y));

    delete *(elementy.begin()+val2);
    elementy.erase(elementy.begin()+val2);
    elementy.insert(elementy.begin()+val2,new Cukierek(pos2.x,pos2.y));

    punkty=+30;
}

void Cukierek::usun4(int val, Cukierek *&c1, int val1, Cukierek *&c2, int val2,Cukierek *&c3,int val3, vector<Cukierek *> &elementy)
{
    auto pos=getPosition();
    auto pos1=c1->getPosition();
    auto pos2=c2->getPosition();
    auto pos3=c3->getPosition();

    delete *(elementy.begin()+val1);
    elementy.erase(elementy.begin()+val1);
    elementy.insert(elementy.begin()+val1,new Cukierek(pos1.x,pos1.y));

    delete *(elementy.begin()+val);
    elementy.erase(elementy.begin()+val);
    elementy.insert(elementy.begin()+val,new Cukierek(pos.x,pos.y));

    delete *(elementy.begin()+val2);
    elementy.erase(elementy.begin()+val2);
    elementy.insert(elementy.begin()+val2,new Cukierek(pos2.x,pos2.y));

    delete *(elementy.begin()+val3);
    elementy.erase(elementy.begin()+val3);
    elementy.insert(elementy.begin()+val3,new Cukierek(pos3.x,pos3.y));

    punkty=+40;
}

void Cukierek::usun5(int val, Cukierek *&c1, int val1, Cukierek *&c2, int val2,Cukierek *&c3,int val3,Cukierek *&c4,int val4, vector<Cukierek *> &elementy)
{
    auto pos=getPosition();
    auto pos1=c1->getPosition();
    auto pos2=c2->getPosition();
    auto pos3=c3->getPosition();
    auto pos4=c4->getPosition();

    delete *(elementy.begin()+val1);
    elementy.erase(elementy.begin()+val1);
    elementy.insert(elementy.begin()+val1,new Cukierek(pos1.x,pos1.y));

    delete *(elementy.begin()+val);
    elementy.erase(elementy.begin()+val);
    elementy.insert(elementy.begin()+val,new Cukierek(pos.x,pos.y));

    delete *(elementy.begin()+val2);
    elementy.erase(elementy.begin()+val2);
    elementy.insert(elementy.begin()+val2,new Cukierek(pos2.x,pos2.y));

    delete *(elementy.begin()+val3);
    elementy.erase(elementy.begin()+val3);
    elementy.insert(elementy.begin()+val3,new Cukierek(pos3.x,pos3.y));

    delete *(elementy.begin()+val4);
    elementy.erase(elementy.begin()+val4);
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

NajlepszyWynik::NajlepszyWynik()
{

}

NajlepszyWynik::NajlepszyWynik(const int x,const int y,const int s)
{
    if (!cyfry.loadFromFile("grafika/cyfry.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    setTexture(cyfry);
    setTextureRect(IntRect(s*15,0,15,24));
    setPosition(x,y);
    cout<<"tworze najlepszy wynik"<<endl;
}

void NajlepszyWynik::wyswietl(string str,vector <NajlepszyWynik*> &najlepsze)
{
    //1100, 273
    for(unsigned int i=0;i<str.length();i++){
        char r=str[i];
        int s=r - '0';
        najlepsze.emplace_back(new NajlepszyWynik(1093+i*15,269,s));
    }
}

string NajlepszyWynik::wczytaj()
{
    fstream plik;
    plik.open("najlepszy.txt",ios::in);
    string str;
    getline(plik,str);
    plik.close();
    return str;
}

void NajlepszyWynik::zapisz(string wynik)
{
    fstream plik;
    plik.open("najlepszy.txt",ios::out);
    plik<<wynik;
    plik.close();
}

AktualnyWynik::AktualnyWynik()
{

}

AktualnyWynik::AktualnyWynik(const int x,const int y,const int s)
{
    if (!cyfry.loadFromFile("grafika/cyfry.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    setTexture(cyfry);
    setTextureRect(IntRect(s*15,0,15,24));
    setPosition(x,y);
}

void AktualnyWynik::wyswietl(const int& punkty,vector <AktualnyWynik*> &wyniki)
{
    if(wyniki.size()!=0){
        for(unsigned int i=0;i<wyniki.size();i++){
        delete *(wyniki.begin()+i);
        wyniki.clear();
        }
    }
    stringstream ss;
    ss<<punkty;
    string str=ss.str();
//    1072, 189
//15x24
    for(unsigned int i=0;i<str.length();i++){
        char r=str[i];
        int s=r - '0';
        wyniki.emplace_back(new AktualnyWynik(1072+i*15,189,s));
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

Zegar::Zegar()
{

}

Zegar::Zegar(int x, int y,int s)
{
    if (!cyfry.loadFromFile("grafika/cyfry.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    setTexture(cyfry);
    setTextureRect(IntRect(s*15,0,15,24));
    setPosition(x,y);
}

void Zegar::odliczanie(Clock &clk,vector <Zegar*> &zegary)
{//1087, 241
    if(zegary.size()!=0){
        for(unsigned int i=0;i<zegary.size();i++){
        delete *(zegary.begin()+i);
        zegary.clear();
        }
    }
    Time elapsed_= clk.restart();
    float z= elapsed_.asSeconds();
    czas=czas-z;
    stringstream ss;
    ss<<czas;
    cout<<czas<<endl;
    string str=ss.str();
    if(czas>=100){
        for(unsigned int i=0;i<3;i++){
        char r=str[i];
        int s=r - '0';
        zegary.emplace_back(new Zegar(1082+i*15,241,s));
        }
    }
    if(czas<100&& czas>=10){
        for(unsigned int i=0;i<2;i++){
            char r=str[i];
            int s=r - '0';
            zegary.emplace_back(new Zegar(1082+i*15,241,s));
        }
    }
    if(czas<10){
        for(unsigned int i=0;i<2;i++){
            char r=str[i];
            int s=r - '0';
            zegary.emplace_back(new Zegar(1082+i*15,241,s));
        }
    }
    if(czas<0){
        cout<<"KONIEC CZASU"<<endl;
        exit(0);
    }

}
