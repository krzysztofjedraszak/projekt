#include "zegar.h"

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

//float Zegar::get_czas()
//{
//    return czas;
//}

//float Zegar::set_czas(float n)
//{
//    czas=n;
//}

//void Zegar::odliczanie(Clock &clk,vector <Zegar*> &zegary)
//{//1087, 241
//    if(zegary.size()!=0){
//        for(unsigned int i=0;i<zegary.size();i++){
//        delete *(zegary.begin()+i);
//        zegary.clear();
//        }
//    }
//    Time elapsed_= clk.restart();
//    float z= elapsed_.asSeconds();
//    czas=czas-z;
//    stringstream ss;
//    ss<<czas;
//    string str=ss.str();
//    if(czas>=100){
//        for(unsigned int i=0;i<3;i++){
//        char r=str[i];
//        int s=r - '0';
//        zegary.emplace_back(new Zegar(1082+i*15,241,s));
//        }
//    }
//    if(czas<100&& czas>=10){
//        for(unsigned int i=0;i<2;i++){
//            char r=str[i];
//            int s=r - '0';
//            zegary.emplace_back(new Zegar(1082+i*15,241,s));
//        }
//    }
//    if(czas<10){
//        for(unsigned int i=0;i<2;i++){
//            char r=str[i];
//            int s=r - '0';
//            zegary.emplace_back(new Zegar(1082+i*15,241,s));
//        }
//    }
//    if(czas<0){
//        cout<<"KONIEC CZASU"<<endl;
//        exit(0);
//    }

//}
