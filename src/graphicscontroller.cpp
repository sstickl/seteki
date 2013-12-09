#include "../include/graphicscontroller.h"

/** CTOR */
GraphicsController::GraphicsController()
{
    window = SDL_CreateWindow( "Seteki", 100, 100, 256, 240, SDL_WINDOW_SHOWN );
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
}

/** DTOR */
GraphicsController::~GraphicsController()
{
    //dtor
    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( window );
}

/** Draws all sprites and handles rendering routines */
void GraphicsController::Draw()
{
    //Reset
    SDL_RenderClear( renderer );

    //Draw Step


    //Present Step
    SDL_RenderPresent( renderer );
}
