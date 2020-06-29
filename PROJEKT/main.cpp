#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <memory>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "candycrushsaga.h"

using namespace std;
using namespace sf;

//bool isclicked(const Vector2i mouse_position,vector<Cukierek*> &elementy ){

//    for(unsigned int i=0;i<elementy.size();i++){
//        FloatRect bounds = elementy[i]->getGlobalBounds();
//        if(mouse_position.x >= bounds.left &&
//           mouse_position.x <= bounds.left+bounds.width &&
//           mouse_position.y >= bounds.top &&
//           mouse_position.y <= bounds.top+bounds.height
//                ){
//            return 1;
//        }
//    }
//}
int main()
{
    RenderWindow window(sf::VideoMode(1280, 720), "CandyCrushSaga");
    Clock clock;
    Plansza p1;

    vector <Cukierek*> elementy;
    vector <Znacznik*> znaczniki;

    for(int j=0;j<10;j++){
        for(int i=0;i<10;i++){
            elementy.emplace_back(new Cukierek(154+i*50,104+j*50));
        }
    }
    int klik=0;
    int x,y,x0,y0;


    while (window.isOpen()) {

        Cukierek* pierwszy_el;
        Cukierek* drugi_el;
//        sf::Time elapsed_ = clock.restart();
//        float elapsed=elapsed_.asSeconds();

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

                    for(unsigned int i=0;i<elementy.size();i++){
                        if(elementy[i]->zaznacz(mouse_pos)){
                            klik++;
                            cout<<"jest klik poczatkowy"<<endl;
                            cout<<"KLIK WYNOSI "<<klik<<endl;
                        }
                        if(klik==1&&elementy[i]->zaznacz(mouse_pos)&&elementy[i]->jest_klikniety==false){
                            pierwszy_el=elementy[i];
                            auto pos=pierwszy_el->getPosition();
                            x0=pos.x;
                            y0=pos.y;
                            znaczniki.emplace_back(new Znacznik (x0,y0));
                            pierwszy_el->jest_klikniety=true;
                            cout<<"tworze nowy kursor"<<endl;
//                            cout<<"jest klik 2"<<endl;
                            cout<<"KLIK WYNOSI "<<klik<<endl;

                        }
                        if(klik==2&&elementy[i]->zaznacz(mouse_pos)&&elementy[i]->jest_klikniety==true){
                            pierwszy_el->jest_klikniety=false;
                            cout<<"usun"<<endl;
                            delete *(znaczniki.begin());
                            znaczniki.erase(znaczniki.begin());
                            klik=0;
                            cout<<"KLIK WYNOSI "<<klik<<endl;
                        }
                        else if(klik==2&&elementy[i]->zaznacz(mouse_pos)&&elementy[i]->jest_klikniety==false){
                            pierwszy_el->jest_klikniety=false;
//tak
                            drugi_el=elementy[i];
                            auto pos2=drugi_el->getPosition();

                            x=pos2.x;
                            y=pos2.y;
                            if(abs(x - x0) + abs(y - y0) == 49){
                                klik=0;
//                                cout<<"przed zamiana pierwszy cukierek"<<x0<<"  "<<y0<<endl;
//                                cout<<"przed zamiana drugi cukierek"<<x<<"  "<<y<<endl;

                                swap(pierwszy_el,drugi_el);
                                auto pos_drugi=drugi_el->getPosition();
                                auto pos_pierwszy=pierwszy_el->getPosition();
                                drugi_el->setPosition(pos_pierwszy.x,pos_pierwszy.y);
                                pierwszy_el->setPosition(pos_drugi.x,pos_drugi.y);
//                                cout<<"po zamiana pierwszy cukierek"<<pos_pierwszy.x<<"  "<<pos_pierwszy.y<<endl;
//                                cout<<"po zamiana drugi cukierek"<<pos_drugi.x<<"  "<<pos_drugi.y<<endl;
                                cout<<"robiona jest zamiana"<<endl;
                                cout<<"KLIK WYNOSI "<<klik<<endl;                                
                                delete *(znaczniki.begin());
                                znaczniki.erase(znaczniki.begin());
                                cout<<endl<<endl<<endl;
                            }
                            else klik=1;
                            cout<<"KLIK WYNOSI "<<klik<<endl;
                        }
                    }
                }
            }

        }

        window.clear(Color::Black);

        window.draw(p1);
        for(auto &s:elementy){
            window.draw(*s);
        }
        for(auto &z:znaczniki){
            window.draw(*z);
        }


        window.display();





  }
    return 0;

}
