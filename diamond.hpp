#include <SDL.h>
//#include  "unit.hpp"
#include "drawing.hpp"
#pragma once

class diamond {
    //friend class RunningMan;
    SDL_Rect srcRect, moverRect;
    public:
    int count = 0 ;
    int frame = 0 ;
    void draw();
    void move();
    diamond();
    diamond(int, int);
    int getX();
    int getY();
}; 