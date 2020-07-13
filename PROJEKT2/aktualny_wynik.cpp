#include "aktualny_wynik.h"

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
