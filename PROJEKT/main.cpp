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
    int klikniecia=1;
    int klik=0;
    int x,y,x0,y0;


    while (window.isOpen()) {

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

//                    for(unsigned int i=0;i<elementy.size();i++){
//                        if(elementy[i]->zaznacz(mouse_pos)){
//                            klik++;
//                            cout<<"jest klik"<<endl;
//                        }
//                        if(klik==1&&elementy[i]->zaznacz(mouse_pos)){
//                            auto pos=elementy[i]->getPosition();
//                            x0=pos.x;
//                            y0=pos.y;
//                        }
//                        if(klik==2&&elementy[i]->zaznacz(mouse_pos)&&elementy[i]->jest_klikniety==false){
//                            auto pos2=elementy[i]->getPosition();
//                            x=pos2.x;
//                            y=pos2.y;
//                            if(abs(x - x0) + abs(y - y0) == 50){
//                                cout<<"zamiana"<<endl;
//                                delete *(znaczniki.begin());
//                                znaczniki.erase(znaczniki.begin());
//                                klik=0;
//                                klikniecia=1;

//                            }
//                            else klik=1;
//                        }
//                    }

                    for(unsigned int i=0;i<elementy.size();i++){
                        if(elementy[i]->zaznacz(mouse_pos)){
                            klik++;
                            cout<<"jest klik 1"<<endl;
                        }
                        if(klik==1&&elementy[i]->zaznacz(mouse_pos)&&elementy[i]->jest_klikniety==false/*&&klikniecia==1*/){
                            auto pos=elementy[i]->getPosition();
                            x0=pos.x;
                            y0=pos.y;
                            znaczniki.emplace_back(new Znacznik (x0,y0));
                            elementy[i]->jest_klikniety=true;
//                            klikniecia=0;
                            cout<<"nowy"<<endl;
                            cout<<"jest klik 2"<<endl;

                        }
                        if(klik==2&&elementy[i]->zaznacz(mouse_pos)&&elementy[i]->jest_klikniety==true/*&&klikniecia==0*/){
//                            klikniecia=1;
                            elementy[i]->jest_klikniety=false;
                            cout<<"usun"<<endl;
                            delete *(znaczniki.begin());
                            znaczniki.erase(znaczniki.begin());
                            klik=0;
                        }
                        else if(klik==2&&elementy[i]->zaznacz(mouse_pos)&&elementy[i]->jest_klikniety==false){
                            auto pos2=elementy[i]->getPosition();
                            x=pos2.x;
                            y=pos2.y;
                            if(abs(x - x0) + abs(y - y0) == 50){
                                cout<<"zamiana"<<endl;
                                delete *(znaczniki.begin());
                                znaczniki.erase(znaczniki.begin());
                                klik=0;
//                                klikniecia=1;

                            }
                            else klik=1;
                        }

                    }
//                    Vector2i mouse_pos = sf::Mouse::getPosition(window);
//                    cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y << endl;

//                    for(unsigned int i=0;i<elementy.size();i++){
//                        if(elementy[i]->zaznacz(mouse_pos)){
//                            klik++;
//                            cout<<"jest klik"<<endl;
//                        }
//                        if(klik==1&&elementy[i]->zaznacz(mouse_pos)){
//                            auto pos=elementy[i]->getPosition();
//                            x0=pos.x;
//                            y0=pos.y;
//                        }
//                        if(klik==2&&elementy[i]->zaznacz(mouse_pos)&&elementy[i]->jest_klikniety==false){
//                            auto pos2=elementy[i]->getPosition();
//                            x=pos2.x;
//                            y=pos2.y;
//                            if(abs(x - x0) + abs(y - y0) == 50){
//                                cout<<"zamiana"<<endl;
//                                delete *(znaczniki.begin());
//                                znaczniki.erase(znaczniki.begin());
//                                klik=0;
//                                klikniecia=1;

//                            }
//                            else klik=1;
//                        }
//                    }

//                    for(unsigned int i=0;i<elementy.size();i++){
//                        if(elementy[i]->zaznacz(mouse_pos)&&elementy[i]->jest_klikniety==false&&klikniecia==1){
//                            auto pos=elementy[i]->getGlobalBounds();
//                            znaczniki.emplace_back(new Znacznik (pos.left,pos.top));
//                            elementy[i]->jest_klikniety=true;
//                            klikniecia=0;
//                            cout<<"nowy"<<endl;

//                        }
//                        else if(elementy[i]->zaznacz(mouse_pos)&&elementy[i]->jest_klikniety==true&&klikniecia==0){
//                            klikniecia=1;
//                            elementy[i]->jest_klikniety=false;
//                            cout<<"usun"<<endl;
//                            delete *(znaczniki.begin());
//                            znaczniki.erase(znaczniki.begin());
//                        }

//                    }
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
