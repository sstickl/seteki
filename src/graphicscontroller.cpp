#include "../include/graphicscontroller.h"

/** CTOR */
GraphicsController::GraphicsController()
{
    window = SDL_CreateWindow( "Seteki", 100, 100, 256, 240, SDL_WINDOW_SHOWN );
    if( window == NULL )
        logSDLError( std::cout, "Error creating window" );

    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    if( renderer == NULL )
        logSDLError( std::cout, "Error creating renderer" );

    bg = new Sprite( "res/img/mainbg.bmp", renderer );
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

    //Draw Step8
    renderTexture( bg->texture, renderer, 0, 0, NULL );

    //Present Step
    SDL_RenderPresent( renderer );
}

void GraphicsController::renderTexture( SDL_Texture *texture, SDL_Renderer *target, SDL_Rect destination, SDL_Rect *clip )
{
    SDL_RenderCopy( target, texture, clip, &destination );
}

void GraphicsController::renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, SDL_Rect *clip )
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	if ( clip != NULL ){
		dst.w = clip->w;
		dst.h = clip->h;
	}
	else
		SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);

	renderTexture(tex, ren, dst, clip);
}
