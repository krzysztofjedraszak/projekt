#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <memory>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "elementsceny.h"
#include "aktualny_wynik.h"
#include "cukierek.h"
#include "najlepszy_wynik.h"
#include "plansza.h"
#include "zegar.h"
#include "znacznik.h"
#include "abstract.h"

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(1280, 720), "CandyCrushSaga");
    Clock clock;
    Plansza p1;
    ElementSceny scena;
    AktualnyWynik akt;
    NajlepszyWynik naj;
    Zegar zegar;
    auto wczytane=naj.wczytaj();

//    vector <Cukierek*> elementy;
//    vector <Znacznik*> znaczniki;
    vector <AktualnyWynik*> wyniki;
    vector <NajlepszyWynik*> najlepsze;
    vector <Zegar*> zegary;
    naj.wyswietl(wczytane,najlepsze);
    akt.wyswietl(scena.get_punkty(),wyniki);

//    ElementSceny elem;
//    for(int j=0;j<10;j++){
//        for(int i=0;i<10;i++){
//    elem.cuksy.emplace_back(new Cukierek(154+i*50,104+j*50,0));
//        }}
//    elem.nazwa();



    scena.stworz_cuksy();



//    for(int j=0;j<10;j++){
//        for(int i=0;i<10;i++){
//            elementy.emplace_back(new Cukierek(154+i*50,104+j*50,0));
//        }
//    }
//    int klik=0;
//    int x,y,x0,y0;
//    Cukierek* pierwszy_el;
//    Cukierek* drugi_el;


    while (window.isOpen()) {

        window.setFramerateLimit(60);
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                std::cout << "Closing Window" << std::endl;
                window.close();
            }
            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {

                    Vector2i mouse_pos = sf::Mouse::getPosition(window);
                    cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y << endl;
                    scena.zrob(mouse_pos);
//                    for(unsigned int i=0;i<elementy.size();i++){

//                        if(elementy[i]->zaznacz(mouse_pos)){
//                            klik++;
//                        }
//                        if(klik==1&&elementy[i]->zaznacz(mouse_pos)&&elementy[i]->get_jest_klikniety()==false){
//                            pierwszy_el=elementy[i];
//                            auto pos=pierwszy_el->getPosition();
//                            x0=pos.x;
//                            y0=pos.y;
//                            znaczniki.emplace_back(new Znacznik (x0,y0));
//                            pierwszy_el->set_jest_klikniety(true);
//                        }
//                        if(klik==2&&elementy[i]->zaznacz(mouse_pos)&&elementy[i]->get_jest_klikniety()==true){
//                            pierwszy_el->set_jest_klikniety(false);
//                            delete *(znaczniki.begin());
//                            znaczniki.erase(znaczniki.begin());
//                            klik=0;
//                            pierwszy_el=nullptr;
//                            drugi_el=nullptr;
//                        }
//                        else if(klik==2&&elementy[i]->zaznacz(mouse_pos)&&elementy[i]->get_jest_klikniety()==false){
//                            pierwszy_el->set_jest_klikniety(false);
//                            drugi_el=elementy[i];
//                            drugi_el->set_jest_klikniety(false);
//                            auto pos2=drugi_el->getPosition();
////                            cout<<x0<<"  "<<y0<< endl;
////                            cout<<pos2.x<<"  "<<pos2.y<<endl;
//                            x=pos2.x;
//                            y=pos2.y;
//                            if(abs(x - x0) + abs(y - y0) == 50){
//                                klik=0;
//                                swap(*pierwszy_el,*drugi_el);
//                                auto pos_drugi=drugi_el->getPosition();
//                                auto pos_pierwszy=pierwszy_el->getPosition();
//                                drugi_el->setPosition(pos_pierwszy.x,pos_pierwszy.y);
//                                pierwszy_el->setPosition(pos_drugi.x,pos_drugi.y);
////                                cout<<pos_pierwszy.x<<"  "<<pos_pierwszy.y<<endl;
////                                cout<<pos_drugi.x<<"  "<<pos_drugi.y<<endl;
//                                delete *(znaczniki.begin());
//                                znaczniki.erase(znaczniki.begin());
//                                cout<<endl<<endl<<endl;
//                                pierwszy_el=nullptr;
//                                drugi_el=nullptr;
//                                cout<<"zamiana"<<endl;
//                                break;
//                            }
//                            else {klik=1;
//                            }
//                        }
//                    }
                }
            }
        }

        scena.match_i_usun();
//        for(int i=0;i<60;i++){
//            if(scena.match(elementy[i],elementy[i+10],elementy[i+20],elementy[i+30],elementy[i+40],5)){
//                scena.usun(elementy[i+10],i+10,elementy[i],i,elementy[i+20],i+20,elementy[i+30],i+30,elementy[i+40],i+40,elementy,5);

//        //5 pionowo
//            }
//        }
//        for(int i=0;i<70;i++){
//            if(scena.match(elementy[i],elementy[i+10],elementy[i+20],elementy[i+30],elementy[i+40],4)){
//                scena.usun(elementy[i+10],i+10,elementy[i],i,elementy[i+20],i+20,elementy[i+30],i+30,elementy[i+40],i+40,elementy,4);

//        //4 pionowo
//            }
//        }
//        for(int i=0;i<80;i++){
//            if(scena.match(elementy[i],elementy[i+10],elementy[i+20],elementy[i+30],elementy[i+40],3)){
//                scena.usun(elementy[i+10],i+10,elementy[i],i,elementy[i+20],i+20,elementy[i+30],i+30,elementy[i+40],i+40,elementy,3);

//        //3 pionowo
//            }
//        }
//        for(int i=0;i<96;i++){
//            if(scena.match(elementy[i],elementy[i+1],elementy[i+2],elementy[i+3],elementy[i+4],5)){
//                scena.usun(elementy[i+1],i+1,elementy[i],i,elementy[i+2],i+2,elementy[i+3],i+3,elementy[i+4],i+4,elementy,5);

//        //5 poziomo
//            }
//        }
//        for(int i=0;i<97;i++){
//            if(scena.match(elementy[i],elementy[i+1],elementy[i+2],elementy[i+3],elementy[i+4],4)){
//                scena.usun(elementy[i+1],i+1,elementy[i],i,elementy[i+2],i+2,elementy[i+3],i+3,elementy[i+4],i+4,elementy,4);

//        //4 poziomo
//            }
//        }
//        for(int i=0;i<98;i++){
//            if(scena.match(elementy[i],elementy[i+1],elementy[i+2],elementy[i+3],elementy[i+4],3)){
//                scena.usun(elementy[i+1],i+1,elementy[i],i,elementy[i+2],i+2,elementy[i+3],i+3,elementy[i+4],i+4,elementy,3);

//        //3 poziomo
//            }
//        }
        if(scena.get_zmiana()==true){
            scena.set_zmiana(false);
            akt.wyswietl(scena.get_punkty(),wyniki);
            naj.zapisz(scena.porownanie(scena.get_punkty(),wczytane,naj,najlepsze));
        }
        zegar.odliczanie(clock,zegary);


        window.clear(Color::Black);

        window.draw(p1);
        for(auto &s:scena.pokaz_cuksy()){
            window.draw(*s);
        }
        for(auto &z:scena.pokaz_znacznik()){
            window.draw(*z);
        }
        for(auto &w:wyniki){
            window.draw(*w);
        }
        for(auto &n:najlepsze){
            window.draw(*n);
        }
        for(auto &z:zegary){
            window.draw(*z);
        }
//        window.draw(w1);
//        window.draw(w2);

        window.display();





  }
    return 0;

}

