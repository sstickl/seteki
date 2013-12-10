#include <iostream>
#include <SDL2/SDL.h>
#include "include/graphicscontroller.h"
#include "include/error.h"

SDL_Texture *loadTexture( const std::string &filename, SDL_Renderer *ren )
{
    SDL_Texture *texture = NULL;    //initialize to nullptr
    SDL_Surface *image = SDL_LoadBMP( filename.c_str() ); //load the image

    //check if image was loaded ok, convert
    if( image != NULL ){
        Uint32 transColor =  SDL_MapRGB( image->format, 255, 0, 255 );
        SDL_SetColorKey( image, SDL_TRUE, transColor );
        texture = SDL_CreateTextureFromSurface( ren, image );
        SDL_FreeSurface( image );
        if( texture == NULL )
            logSDLError( std::cout, "Create not create texture");
    }
    else
        logSDLError( std::cout, "Could not load BMP");

    return texture;
}

/*void renderTexture( SDL_Texture *texture, SDL_Renderer *target, SDL_Rect destination, SDL_Rect *clip = NULL )
{
    SDL_RenderCopy( target, texture, clip, &destination );
}

void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, SDL_Rect *clip = NULL )
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
}*/

int main(int argc, char **argv){
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		logSDLError( std::cout, "Could not intialize SDL");
		return 1;
	}

	GraphicsController graphicsController;

	/*SDL_Window *window = SDL_CreateWindow( "Seteki", 100, 100, 256, 240, SDL_WINDOW_SHOWN );
	if( window == NULL ){
        logSDLError( std::cout, "Could not create window");
        return 1;
	}

    SDL_Renderer *render = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    if( render == NULL )
        return 1;

    SDL_Texture *textbg = loadTexture( "res/img/mainbg.bmp", render );
    SDL_Texture *fro = loadTexture( "res/img/transparenttest.bmp", render );*/

    bool quit = false;
    SDL_Event e;
    //SDL_Rect testclip;
    //testclip.x = 7;
    //testclip.y = 33;
    //testclip.w = 31;
    //testclip.h = 12;

    while( !quit )
    {
        //Handle events
        while( SDL_PollEvent( &e ) )
        {
            if( e.type == SDL_QUIT )
                quit = true;
        }

        graphicsController.Draw();
        //Render
        //renderTexture( textbg, render, 0, 0 );
        //renderTexture( fro, render, 200, 150, &testclip );
    }
    //SDL_DestroyTexture( textbg );
    /*SDL_DestroyRenderer( render );
    SDL_DestroyWindow( window );*/

	SDL_Quit();

	return 0;
}
