#include<iostream>
#include "HUMania.hpp"
#include <vector>
#include<cmath>
using namespace std;


// First rectangle is srcRect, second is moverRect
// these values are taken from the corresponding image in assets file
// use spritecow.com to find exact values of other asset images
Unit pigeon = {{7,88,155,103}, {30, 40, 50, 50}};
// Unit pigeon_1 = {{0, 273, 153, 84}, {30, 40, 50, 50}};
// Unit pigeon_2 = {{2,361,159,124}, {30, 40, 50, 50}};
vector<Unit> pigeons;

//create 2 more vectors for bees and butterflies
Unit butterfly = {{257,24,173,134}, {30, 40, 50, 50}};
// Unit butterfly_1 = {{257,182,192,214}, {30, 40, 50, 50}};
// Unit butterfly_2 = {{248,432,248,179}, {30, 40, 50, 50}};
vector<Unit> butterflies;

Unit bee = {{527, 138, 194, 116}, {30, 40, 50, 50}};
// Unit bee_1 = {{527, 254, 194, 116}, {30, 40, 50, 50}};
// Unit bee_2 = {{540, 370, 193, 115}, {30, 40, 50, 50}};
vector<Unit> bees;

// Pigeon::Pigeon(){
//     Unit::srcRect = {7,88,155,103};
//     Unit::moverRect = {30, 40, 50, 50};
// };

// Pigeon::Pigeon(int x, int y){
//     Unit::srcRect = {7,88,155,103};
//     Unit::moverRect = {x, y, 50, 50};
// };

// void Pigeon::anime(){
//     switch(state){
//         case 0:
//             srcRect = {7,88,155,103}; state = 1; break;
//         case 1:
//             srcRect = {0, 273, 153, 84}; state = 2; break;
//         case 2:
//             srcRect = {2,361,159,124}; state = 0; break;
//     }

//     if(moverRect.x >= 1000)
//         moverRect.x = 0;
//     else{moverRect.x += 10;}
// }

void drawObjects(SDL_Renderer* gRenderer, SDL_Texture* assets){

    // this functios is drawing one pigeon, one butterfly, and one bee at the same point only right now
    // SDL_RenderCopy(gRenderer, assets, &pigeon.srcRect, &pigeon.moverRect); pigeon.moverRect.x += 10;
    // SDL_RenderCopy(gRenderer, assets, &butterfly.srcRect, &butterfly.moverRect); butterfly.moverRect.x += 5;
    // SDL_RenderCopy(gRenderer, assets, &bee.srcRect, &bee.moverRect); bee.moverRect.x += 2;
    // pigeons.push_back(pigeon); pigeons.push_back(pigeon_1); pigeons.push_back(pigeon_2);
    // TODO: Write code to iterate over all the vectors and draw objects here: 
    int iter_p = 0; int iter_beautifly = 0; int iter_shehed_ki_makhi = 0;
    while(iter_p < pigeons.size()){
        SDL_RenderCopy(gRenderer, assets, &pigeons[iter_p].srcRect, &pigeons[iter_p].moverRect);
        pigeons[iter_p].moverRect.x += 10; //moves pigeon 10 units on positive x axis -> towards the right
        pigeons[iter_p].moverRect.y -= 5; //moves pigeon 5 units towards up of screen 
        int x = pigeons[iter_p].moverRect.x % 3; //takes mod 3 on x to get 0, 1, and 2 respectively to state changes accordingly
        //if moverRect is changing doesn't that mean k iter_0 is also changing hence things are moving, then why?
        if(x == 0) pigeons[iter_p].srcRect = {0, 273, 153, 84};
        else if(x == 1) pigeons[iter_p].srcRect = {2,361,159,124};
        else if(x == 2) pigeons[iter_p].srcRect = {7,88,155,103};

        if(pigeons[iter_p].moverRect.x >= 1000) pigeons[iter_p].moverRect.x = 0; //pigeon emerges from the left when it reaches the end of screen on right
        if(pigeons[iter_p].moverRect.y <= 0) pigeons[iter_p].moverRect.y = 600; //pigeon emerges from the bottom when it reaches the end of screen on top
        iter_p++; //cout << iter_p << endl;//why is iter not changing and is only 1 throughout? whyyy? Tell me whyyy
    };
    
    while(iter_beautifly < butterflies.size()){
        SDL_RenderCopy(gRenderer, assets, &butterflies[iter_beautifly].srcRect, &butterflies[iter_beautifly].moverRect);
        butterflies[iter_beautifly].moverRect.x += 5;
        int x = 2*butterflies[iter_beautifly].moverRect.x % 3;

        if(x == 0) butterflies[iter_beautifly].srcRect = {257,182,192,214};
        else if (x == 1) butterflies[iter_beautifly].srcRect = {248,432,248,179};
        else if (x == 2) butterflies[iter_beautifly].srcRect = {257,24,173,134};

        if(butterflies[iter_beautifly].moverRect.x >= 1000)
            butterflies[iter_beautifly].moverRect.x = 0;
        iter_beautifly++;
    }

    while(iter_shehed_ki_makhi < bees.size()){
        SDL_RenderCopy(gRenderer, assets, &bees[iter_shehed_ki_makhi].srcRect, &bees[iter_shehed_ki_makhi].moverRect);
        bees[iter_shehed_ki_makhi].moverRect.x += 2;
        bees[iter_shehed_ki_makhi].moverRect.y += 2;
        int x = 5*bees[iter_shehed_ki_makhi].moverRect.x % 3;

        if(x == 0) bees[iter_shehed_ki_makhi].srcRect = {527, 254, 194, 116} ;
        if(x == 1) bees[iter_shehed_ki_makhi].srcRect = {540, 370, 193, 115} ;
        if(x == 2) bees[iter_shehed_ki_makhi].srcRect = {527, 138, 194, 116} ;

        if(bees[iter_shehed_ki_makhi].moverRect.x >= 1000) bees[iter_shehed_ki_makhi].moverRect.x = 0;
        if(bees[iter_shehed_ki_makhi].moverRect.y >= 600) bees[iter_shehed_ki_makhi].moverRect.y = 0;
        iter_shehed_ki_makhi++;
    }
    
    
    // pigeon.moverRect.x+=10; // moves the pigeon 10 pixel towards right
    // changing the srcRect to other positions of pigeon will make the fly animation
    // SDL_RenderPresent is already called in game.cpp file, you don't need to call here
    // butterfly.moverRect.x += 5; bee.moverRect.x+= 2;
}

void createObject(int x, int y){

    // TODO: create an object randomly, and push it into corresponding vector
    std::cout<<"Mouse clicked at: "<<x<<" -- "<<y<<std::endl;
    
    /* Sets moverRect coordinates to the point at which it was clicked and initializes that point as the point at which
     the sprite will generate. */
    // pigeon ={{527, 138, 194, 116}, {x, y, 50, 50}};
    // butterfly ={{257,24,173,134}, {x, y, 50, 50}};
    // bee ={{527, 138, 194, 116}, {x, y, 50, 50}};
    pigeon.moverRect = {x, y, 50, 50};
    butterfly.moverRect = {x, y, 50, 50};
    bee.moverRect = {x, y, 50, 50};

    /* Randomly generates a number between 0 and 2, and then the sprite is selected based on the number that was selected.
    The sprite initial state is pushed onto its corresponding Unit Vector.*/
    int val = rand() % 3;
    if(val == 0) pigeons.push_back(pigeon);
    else if(val == 1) butterflies.push_back(butterfly);
    else if (val == 2) bees.push_back(bee);
    
}

