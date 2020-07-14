#include "abstract.h"

Abstract::Abstract()
{

}

bool Abstract::zaznacz(const Vector2i mouse_position)
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
