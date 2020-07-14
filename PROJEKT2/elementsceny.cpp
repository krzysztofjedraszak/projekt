#include "elementsceny.h"
#include "najlepszy_wynik.h"
#include "cukierek.h"
#include "znacznik.h"


ElementSceny::ElementSceny()
{
    punkty=0;
    klik=0;
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

void ElementSceny::usun(Cukierek *&c,int val, Cukierek *&c1, int val1, Cukierek *&c2, int val2, Cukierek *&c3, int val3, Cukierek *&c4, int val4, vector<Cukierek *> &cuksy, int ile)
{
    if(ile==5){
        auto pos=c->getPosition();
        auto pos1=c1->getPosition();
        auto pos2=c2->getPosition();
        auto pos3=c3->getPosition();
        auto pos4=c4->getPosition();

        delete *(cuksy.begin()+val1);
        cuksy.erase(cuksy.begin()+val1);
        cuksy.insert(cuksy.begin()+val1,new Cukierek(pos1.x,pos1.y,0));

        delete *(cuksy.begin()+val);
        cuksy.erase(cuksy.begin()+val);
        cuksy.insert(cuksy.begin()+val,new Cukierek(pos.x,pos.y,0));

        delete *(cuksy.begin()+val2);
        cuksy.erase(cuksy.begin()+val2);
        cuksy.insert(cuksy.begin()+val2,new Cukierek(pos2.x,pos2.y,0));

        delete *(cuksy.begin()+val3);
        cuksy.erase(cuksy.begin()+val3);
        cuksy.insert(cuksy.begin()+val3,new Cukierek(pos3.x,pos3.y,0));

        delete *(cuksy.begin()+val4);
        cuksy.erase(cuksy.begin()+val4);
        cuksy.insert(cuksy.begin()+val4,new Cukierek(pos4.x,pos4.y,0));

        punkty+=50;
        czy_zmiana_wyniku=true;
    }
    if(ile==4){
        auto pos=c->getPosition();
        auto pos1=c1->getPosition();
        auto pos2=c2->getPosition();
        auto pos3=c3->getPosition();

        delete *(cuksy.begin()+val1);
        cuksy.erase(cuksy.begin()+val1);
        cuksy.insert(cuksy.begin()+val1,new Cukierek(pos1.x,pos1.y,0));

        delete *(cuksy.begin()+val);
        cuksy.erase(cuksy.begin()+val);
        cuksy.insert(cuksy.begin()+val,new Cukierek(pos.x,pos.y,0));

        delete *(cuksy.begin()+val2);
        cuksy.erase(cuksy.begin()+val2);
        cuksy.insert(cuksy.begin()+val2,new Cukierek(pos2.x,pos2.y,0));

        delete *(cuksy.begin()+val3);
        cuksy.erase(cuksy.begin()+val3);
        cuksy.insert(cuksy.begin()+val3,new Cukierek(pos3.x,pos3.y,0));

        punkty+=40;
        czy_zmiana_wyniku=true;
    }
    if(ile==3){
        auto pos=c->getPosition();
        auto pos1=c1->getPosition();
        auto pos2=c2->getPosition();

        delete *(cuksy.begin()+val1);
        cuksy.erase(cuksy.begin()+val1);
        cuksy.insert(cuksy.begin()+val1,new Cukierek(pos1.x,pos1.y,0));

        delete *(cuksy.begin()+val);
        cuksy.erase(cuksy.begin()+val);
        cuksy.insert(cuksy.begin()+val,new Cukierek(pos.x,pos.y,0));

        delete *(cuksy.begin()+val2);
        cuksy.erase(cuksy.begin()+val2);
        cuksy.insert(cuksy.begin()+val2,new Cukierek(pos2.x,pos2.y,0));

        punkty+=30;
        czy_zmiana_wyniku=true;
    }
}

vector<Cukierek *> ElementSceny::stworz_cuksy()
{
    for(int j=0;j<10;j++){
        for(int i=0;i<10;i++){
            cuksy.emplace_back(new Cukierek(154+i*50,104+j*50,0));
        }
    }
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

void ElementSceny::zrob(const Vector2i mouse_pos)
{
    for(unsigned int i=0;i<cuksy.size();i++){

        if(cuksy[i]->zaznacz(mouse_pos)){
            klik++;
            cout<<"klik 1"<<endl;
        }
        if(klik==1&&cuksy[i]->zaznacz(mouse_pos)&&cuksy[i]->get_jest_klikniety()==false){
            pierwszy_el=cuksy[i];
            auto pos=pierwszy_el->getPosition();
            x0=pos.x;
            y0=pos.y;
            znaczniki.emplace_back(new Znacznik(x0,y0));
            pierwszy_el->set_jest_klikniety(true);
            cout<<"tworzenei znacznika"<<endl;
        }
        if(klik==2&&cuksy[i]->zaznacz(mouse_pos)&&cuksy[i]->get_jest_klikniety()==true){
            pierwszy_el->set_jest_klikniety(false);
            delete *(znaczniki.begin());
            znaczniki.erase(znaczniki.begin());
            klik=0;
            pierwszy_el=nullptr;
            drugi_el=nullptr;
            cout<<"usuwanie znacznika"<<endl;
        }
        else if(klik==2&&cuksy[i]->zaznacz(mouse_pos)&&cuksy[i]->get_jest_klikniety()==false){
            pierwszy_el->set_jest_klikniety(false);
            drugi_el=cuksy[i];
            drugi_el->set_jest_klikniety(false);
            auto pos2=drugi_el->getPosition();
//                            cout<<x0<<"  "<<y0<< endl;
//                            cout<<pos2.x<<"  "<<pos2.y<<endl;
            x=pos2.x;
            y=pos2.y;
            if(abs(x - x0) + abs(y - y0) == 50){
                klik=0;
                swap(*pierwszy_el,*drugi_el);
                auto pos_drugi=drugi_el->getPosition();
                auto pos_pierwszy=pierwszy_el->getPosition();
                drugi_el->setPosition(pos_pierwszy.x,pos_pierwszy.y);
                pierwszy_el->setPosition(pos_drugi.x,pos_drugi.y);
//                                cout<<pos_pierwszy.x<<"  "<<pos_pierwszy.y<<endl;
//                                cout<<pos_drugi.x<<"  "<<pos_drugi.y<<endl;
                delete *(znaczniki.begin());
                znaczniki.erase(znaczniki.begin());
                cout<<endl<<endl<<endl;
                pierwszy_el=nullptr;
                drugi_el=nullptr;
                cout<<"zamiana"<<endl;
                break;
            }
            else {klik=1;
            }
        }
    }
}

vector<Cukierek*> ElementSceny::pokaz_cuksy()
{
    return cuksy;
}

vector<Znacznik *> ElementSceny::pokaz_znacznik()
{
    return znaczniki;
}

void ElementSceny::match_i_usun()
{
            for(int i=0;i<60;i++){
                if(match(cuksy[i],cuksy[i+10],cuksy[i+20],cuksy[i+30],cuksy[i+40],5)){
                    usun(cuksy[i+10],i+10,cuksy[i],i,cuksy[i+20],i+20,cuksy[i+30],i+30,cuksy[i+40],i+40,cuksy,5);

            //5 pionowo
                }
            }
            for(int i=0;i<70;i++){
                if(match(cuksy[i],cuksy[i+10],cuksy[i+20],cuksy[i+30],cuksy[i+40],4)){
                    usun(cuksy[i+10],i+10,cuksy[i],i,cuksy[i+20],i+20,cuksy[i+30],i+30,cuksy[i+40],i+40,cuksy,4);

            //4 pionowo
                }
            }
            for(int i=0;i<80;i++){
                if(match(cuksy[i],cuksy[i+10],cuksy[i+20],cuksy[i+30],cuksy[i+40],3)){
                    usun(cuksy[i+10],i+10,cuksy[i],i,cuksy[i+20],i+20,cuksy[i+30],i+30,cuksy[i+40],i+40,cuksy,3);

            //3 pionowo
                }
            }
            for(int i=0;i<96;i++){
                if(match(cuksy[i],cuksy[i+1],cuksy[i+2],cuksy[i+3],cuksy[i+4],5)){
                    usun(cuksy[i+1],i+1,cuksy[i],i,cuksy[i+2],i+2,cuksy[i+3],i+3,cuksy[i+4],i+4,cuksy,5);

            //5 poziomo
                }
            }
            for(int i=0;i<97;i++){
                if(match(cuksy[i],cuksy[i+1],cuksy[i+2],cuksy[i+3],cuksy[i+4],4)){
                    usun(cuksy[i+1],i+1,cuksy[i],i,cuksy[i+2],i+2,cuksy[i+3],i+3,cuksy[i+4],i+4,cuksy,4);

            //4 poziomo
                }
            }
            for(int i=0;i<98;i++){
                if(match(cuksy[i],cuksy[i+1],cuksy[i+2],cuksy[i+3],cuksy[i+4],3)){
                    usun(cuksy[i+1],i+1,cuksy[i],i,cuksy[i+2],i+2,cuksy[i+3],i+3,cuksy[i+4],i+4,cuksy,3);

            //3 poziomo
                }
            }
}










