#include "position.hpp"
#include "performance.hpp"

class spaceship{
    position coord;
    performance health;
    //image 
    public:
        spaceship(){
            coord.x = 0;
            coord.y = 50;
        }
        void moveup(){
            coord.y++; // y coordinate must increase when this function is called.
            coord.x++; // x coordinate will also be increased as the ship keeps on moving.
        }
        void move_down(){
            coord.y--; // y coordinate must decrease when this function is called.
            coord.x++; // x coordinate will also be increased as the ship keeps on moving.
        }
        // void shoot(){ what are we doing here
        //     //what type of attck
        //     //what happen when attacked?
        // }
};