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

int main()
{
    RenderWindow window(sf::VideoMode(1280, 720), "CandyCrushSaga");
    Clock clock;
    Plansza p1;

    while (window.isOpen()) {

        sf::Time elapsed_ = clock.restart();
//        float elapsed=elapsed_.asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                std::cout << "Closing Window" << std::endl;
                window.close();
            }
        }

        window.clear(Color::Black);

        window.draw(p1);

        window.display();





  }
    return 0;

}
