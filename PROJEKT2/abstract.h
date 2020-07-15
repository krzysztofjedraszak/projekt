#ifndef ABSTRACT_H
#define ABSTRACT_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>
using namespace sf;
using namespace std;

class Abstract: public Sprite
{
public:
    Abstract();
    bool zaznacz(const Vector2i mouse_position);
};

#endif // ABSTRACT_H
