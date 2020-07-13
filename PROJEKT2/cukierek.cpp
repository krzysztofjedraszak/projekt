#include "cukierek.h"

Cukierek::Cukierek(int x,int y,int z)
{
    if(z==4){
        if (!specjalne.loadFromFile("grafika/specjalne.png")) {
            std::cerr << "Could not load texture" << std::endl;
        }
//        typ=44;
        setTexture(specjalne);
        setTextureRect(IntRect(196,0,49,49));
        setPosition(x,y);
        jest_klikniety=false;
    }
    else{
    if (!cukierek.loadFromFile("grafika/cukierki.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    typ=rand()%7;
    setTexture(cukierek);
    setTextureRect(IntRect(typ*49,0,49,49));
    setPosition(x,y);
    jest_klikniety=false;
    }
}
//Cukierek::Cukierek(int x, int y, int z)
//{
//    if(z==4){
//        if (!specjalne.loadFromFile("grafika/specjalne.png")) {
//            std::cerr << "Could not load texture" << std::endl;
//        }
//        typ=44;
//        setTexture(specjalne);
//        setTextureRect(IntRect(196,0,49,49));
//        setPosition(x,y);
//        jest_klikniety=false;
//    }
//}


//152x104 poczatek pola
void Cukierek::zamiana()
{

}

//bool Cukierek::match3(Cukierek* &c1, Cukierek* &c2)
//{
//    auto pos=getPosition();
//    auto pos1=c1->getPosition();
//    auto pos2=c2->getPosition();
//    if((typ==c1->typ&&typ==c2->typ&&pos.x==pos1.x&&pos.x==pos2.x)||
//           (typ==c1->typ&&typ==c2->typ&&pos.y==pos1.y&&pos.y==pos2.y)){
//        return 1;
//    }
//    else return 0;
//}

//bool Cukierek::match4(Cukierek *&c1, Cukierek *&c2, Cukierek *&c3)
//{
//    auto pos=getPosition();
//    auto pos1=c1->getPosition();
//    auto pos2=c2->getPosition();
//    auto pos3=c3->getPosition();
//    if((typ==c1->typ&&typ==c2->typ&&typ==c3->typ&&pos.x==pos1.x&&pos.x==pos2.x&&pos.x==pos3.x)||
//       (typ==c1->typ&&typ==c2->typ&&typ==c3->typ&&pos.y==pos1.y&&pos.y==pos2.y&&pos.y==pos3.y)){
//        return 1;
//    }
//    else return 0;
//}

//bool Cukierek::match5(Cukierek *&c1, Cukierek *&c2, Cukierek *&c3, Cukierek *&c4)
//{
//    auto pos=getPosition();
//    auto pos1=c1->getPosition();
//    auto pos2=c2->getPosition();
//    auto pos3=c3->getPosition();
//    auto pos4=c4->getPosition();
//    if((typ==c1->typ&&typ==c2->typ&&typ==c3->typ&&typ==c4->typ&&pos.x==pos1.x&&pos.x==pos2.x&&pos.x==pos3.x&&pos.x==pos4.x)||
//       (typ==c1->typ&&typ==c2->typ&&typ==c3->typ&&typ==c4->typ&&pos.y==pos1.y&&pos.y==pos2.y&&pos.y==pos3.y&&pos.y==pos4.y)){
//        return 1;
//    }
//    else return 0;
//}

void Cukierek::usun3(int val,Cukierek*& c1,int val1,Cukierek*& c2,int val2,vector <Cukierek*> &elementy)
{
    auto pos=getPosition();
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

    punkty=+50;
}
