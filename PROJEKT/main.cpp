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

    for(int j=0;j<10;j++){
    for(int i=0;i<10;i++){
        elementy.emplace_back(new Cukierek(154+i*50,104+j*50));
    }
    }




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

                    for(unsigned int i=0;i<elementy.size();i++){
                        elementy[i]->zaznaczcukierek(mouse_pos);
                }

            }
        }
}
        window.clear(Color::Black);

        window.draw(p1);
        for(auto &s:elementy){
            window.draw(*s);
        }

        window.display();





  }
    return 0;

}
