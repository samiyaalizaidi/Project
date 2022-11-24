#include "attack.hpp"

void Attack::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}
void Attack::move_NorthEast(){
    moverRect.x += 10;
    moverRect.y -= 10;
}

void Attack::move_NorthWest(){
    moverRect.x -= 10;
    moverRect.y -= 10;
}

void Attack::move_SouthEast(){
    moverRect.x += 10;
    moverRect.y += 10;
}

void Attack::move_SouthWest(){
    moverRect.x -= 10;
    moverRect.y += 10;
}