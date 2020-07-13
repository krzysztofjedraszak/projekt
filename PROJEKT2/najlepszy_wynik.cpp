#include "najlepszy_wynik.h"

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
