#include "cloudmanager.hpp"

void cloudmanager::creatobj(){
    check++;
    if (check >50){
    // cout << "cloud created"<<endl;
    clouds *c1 = new clouds(30,100);
    cld.push_back(c1); 
    check=0;
}
}
void cloudmanager::creatobj1(){
    check1++;
    if (check1 >45){
    // cout << "cloud created1"<<endl;
    clouds1 *c2 = new clouds1(0,300);
    cld1.push_back(c2); 
    check1=0;
}
}
void cloudmanager::drawobj(){
    int size=0;
    while(size<cld.size()){
        cld[size]->draw();
        cld[size]->move();
        size++;
    }
}
void cloudmanager::drawobj1(){
    int size=0;
    while(size<cld1.size()){
        cld1[size]->draw();
        cld1[size]->move();
        size++;
        }
   
    }

//diamond
void cloudmanager::creatobj2(){
    check2++;
    if (check2 >50){
    int x = rand() % 4;
    diamond *d1;
    switch (x)
    {
        case 0:
                // cout << "diamond created1"<<endl;
                d1 = new diamond(1200,300);
                break;
        case 1:
                // cout << "diamond created2"<<endl;
                d1 = new diamond(1200,150);
                break;
        case 2:
                // cout << "diamond created3"<<endl;
                d1 = new diamond(1200,590);
                break;
        case 3: 
                // cout << "diamond created4"<<endl;
                d1 = new diamond(1200,20);
                break;


        default:
            break;
    }
    dim.push_back(d1);
    check2=0;
    }
}
void cloudmanager::drawobj2(){
    int size=0;
    while(size<dim.size()){
        if(dim[size] != NULL){
        dim[size]->draw();
        dim[size]->move();
        size++;
        }
    }
}

cloudmanager::~cloudmanager(){
    int size=0;
    while(size<cld.size()){
        delete cld[size];
        cld[size] = NULL;
        size++;
    }
    cout << "clouds deleted" << endl; 
}

bool cloudmanager::DetectCollision(SDL_Rect coord){
    int h = coord.h; 
    int w = coord.w;
    int x = coord.x;
    int y = coord.y;
    int i = 0; // to keep track of the index.
    int s = 50; // diamond's size. can be used for both w and h.

    /*  COLLISION DETECTION LOGIC EXPLANATION

        x1,y1___________x2,y1
            |           |  
            |           |
        x1,y2___________x2,y2  

        diamond has -> x, y, w, h
        if x1 = x OR x1 = x + w OR x2 = x OR x2 = x + w 
            -> y is in range [y1, y2] OR (y + h) is in range [y1, y2]     
        if y1 = y OR y1 = y + h OR y2 = y OR y2 = y + h
            -> x is in range [x1, x2] OR (x + w) is in range [x1, x2]
    */


    for(auto diamond : dim){
        if(((x + w) == diamond->getX()) || (x == diamond->getX())){
            if((diamond->getY() >= y && diamond->getY() <= (y + h)) || ((diamond->getY() + s) >= y && (diamond->getY() + s) < (y + h))){
                delete diamond;
                diamond = NULL;
                dim.erase(dim.begin() + i);
                cout << "diamond deleted" << endl;
                diamondsCollected++;
                return true;
            }
        }
        else if(((x + w) == diamond->getX() + s) || (x == diamond->getX() + s)){
            if((diamond->getY() >= y && diamond->getY() <= (y + h)) || ((diamond->getY() + s) >= y && (diamond->getY() + s) < (y + h))){
                delete diamond;
                diamond = NULL;
                dim.erase(dim.begin() + i);
                cout << "diamond deleted" << endl;
                diamondsCollected++;
                return true;
            }
        }
        else if((diamond->getY() == y) || ((y + h) == diamond->getY())){
            if((diamond->getX() >= x && diamond->getX() <= (x + w)) || ((diamond->getX() + s) >= x && (diamond->getX() + s) <= (x + w))){
                delete diamond;
                diamond = NULL;
                dim.erase(dim.begin() + i);
                cout << "diamond deleted" << endl;
                diamondsCollected++;
                return true;
            }
        }
        else if((diamond->getY() + s == y) || ((y + h) == diamond->getY() + s)){
            if((diamond->getX() >= x && diamond->getX() <= (x + w)) || ((diamond->getX() + s) >= x && (diamond->getX() + s) <= (x + w))){
                delete diamond;
                diamond = NULL;
                dim.erase(dim.begin() + i);
                cout << "diamond deleted" << endl;
                diamondsCollected++;
                return true;
            }
        }
        i++;
    }
    return false;
}