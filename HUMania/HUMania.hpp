#include<SDL.h>


void drawObjects(SDL_Renderer* gRnderer, SDL_Texture* assets);
void createObject(int x, int y);

struct Unit{
SDL_Rect srcRect, moverRect;
};

// class Pigeon :: Unit{
//     int state = 0;
//     public:
//     // void draw(SDL_Renderer*, SDL_Texture* assets)
//     Pigeon();
//     Pigeon(int x, int y);
//     void anime();
// };