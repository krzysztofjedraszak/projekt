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
    Cukierek* pierwszy_el;
    Cukierek* drugi_el;
    Time time =seconds( 1 );

    while (window.isOpen()) {

        window.setFramerateLimit(60);

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
                        }
                        if(klik==1&&elementy[i]->zaznacz(mouse_pos)&&elementy[i]->jest_klikniety==false){
                            pierwszy_el=elementy[i];
                            auto pos=pierwszy_el->getPosition();
                            x0=pos.x;
                            y0=pos.y;
                            znaczniki.emplace_back(new Znacznik (x0,y0));
                            pierwszy_el->jest_klikniety=true;
                        }
                        if(klik==2&&elementy[i]->zaznacz(mouse_pos)&&elementy[i]->jest_klikniety==true){
                            pierwszy_el->jest_klikniety=false;
                            delete *(znaczniki.begin());
                            znaczniki.erase(znaczniki.begin());
                            klik=0;
                            pierwszy_el=nullptr;
                            drugi_el=nullptr;
                        }
                        else if(klik==2&&elementy[i]->zaznacz(mouse_pos)&&elementy[i]->jest_klikniety==false){
                            pierwszy_el->jest_klikniety=false;
                            drugi_el=elementy[i];
                            drugi_el->jest_klikniety=false;
                            auto pos2=drugi_el->getPosition();
                            x=pos2.x;
                            y=pos2.y;
                            if(abs(x - x0) + abs(y - y0) == 50){
                                klik=0;
                                swap(*pierwszy_el,*drugi_el);
                                auto pos_drugi=drugi_el->getPosition();
                                auto pos_pierwszy=pierwszy_el->getPosition();
                                drugi_el->setPosition(pos_pierwszy.x,pos_pierwszy.y);
                                pierwszy_el->setPosition(pos_drugi.x,pos_drugi.y);
                                delete *(znaczniki.begin());
                                znaczniki.erase(znaczniki.begin());
                                cout<<endl<<endl<<endl;
                                pierwszy_el=nullptr;
                                drugi_el=nullptr;
                                break;
                            }
                            else {klik=1;
                            }
                        }
                    }
                }
            }
        }






        for(int i=0;i<80;i++){
            if(elementy[i+10]->match(elementy[i],elementy[i+20])){
                auto pos1=elementy[i]->getPosition();
                auto pos2=elementy[i+10]->getPosition();
                auto pos3=elementy[i+20]->getPosition();
                cout<<"dziala"<<endl;

                delete *(elementy.begin()+i);
                elementy.erase(elementy.begin()+i);cout<<elementy.size()<<endl;
                elementy.insert(elementy.begin()+i,new Cukierek(pos1.x,pos1.y));

                delete *(elementy.begin()+i+10);
                elementy.erase(elementy.begin()+i+10);cout<<elementy.size()<<endl;
                elementy.insert(elementy.begin()+i+10,new Cukierek(pos2.x,pos2.y));

                delete *(elementy.begin()+i+20);
                elementy.erase(elementy.begin()+i+20);cout<<elementy.size()<<endl;
                elementy.insert(elementy.begin()+i+20,new Cukierek(pos3.x,pos3.y));



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

//                sleep( time );
//                    koniec przycisniecia myszki 52,62,72

        window.display();





  }
    return 0;

}
