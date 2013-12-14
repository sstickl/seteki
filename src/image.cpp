#include "../include/image.h"

/** CTOR */
Sprite::Sprite( const std::string filename, SDL_Renderer *ren )
{
    //load the image
    texture = NULL;    //initialize to nullptr
    SDL_Surface *image = IMG_Load( filename.c_str() ); //load the image

    //check if image was loaded ok, convert
    if( image != NULL ){
        //Create texture, release surface
        texture = SDL_CreateTextureFromSurface( ren, image );
        SDL_FreeSurface( image );

        //error check
        if( texture == NULL )
            logSDLError( std::cout, "Create not create texture");
    }
    else
        logSDLError( std::cout, "Could not load image");

    m_Counter = 1;  //initialize counter to 1
}

/** DTOR */
Sprite::~Sprite()
{
    SDL_DestroyTexture( texture );  //unload the texture
}
