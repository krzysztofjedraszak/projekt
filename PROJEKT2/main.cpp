#include <iostream>
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
    scena.wyswietl_naj_wynik(scena.wczytaj_naj_wynik());
    scena.wyswietl_aktualny(scena.get_punkty());
    scena.stworz_cuksy();

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
                }
            }
        }
        scena.match_i_usun();
        scena.jesli_zmiana_wyniku(scena);
        scena.odliczanie(clock);
        scena.pokaz_wszystko(window,scena,p1);
  }
    return 0;

}

