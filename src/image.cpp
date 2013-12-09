#include "../include/image.h"

/** CTOR */
image::image( const std::string filename, SDL_Renderer *ren )
{
    //load the image
    texture = NULL;    //initialize to nullptr
    SDL_Surface *image = SDL_LoadBMP( filename.c_str() ); //load the image

    //check if image was loaded ok, convert
    if( image != NULL ){
        //Set transparency
        Uint32 transColor =  SDL_MapRGB( image->format, 255, 0, 255 );
        SDL_SetColorKey( image, SDL_TRUE, transColor );

        //Create texture, release surface
        texture = SDL_CreateTextureFromSurface( ren, image );
        SDL_FreeSurface( image );

        //error check
        if( texture == NULL )
            logSDLError( std::cout, "Create not create texture");
    }
    else
        logSDLError( std::cout, "Could not load BMP");

    m_Counter = 1;  //initialize counter to 1
}

/** DTOR */
image::~image()
{
    SDL_DestroyTexture( texture );  //unload the texture
}
