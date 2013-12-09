#ifndef IMAGE_H
#define IMAGE_H
#include <SDL2/SDL.h>
#include <iostream>
#include "error.h"

class image
{
    public:
        image( const std::string, SDL_Renderer *);    //ctor
        virtual ~image();   //dtor

        void incCounter() { m_Counter++; }
        void decCounter() { m_Counter--; }

    protected:

    private:
        unsigned int m_Counter; //Holds how many objects are referencing this image -- if 0, destruct
        SDL_Texture *texture;   //Holds image data
};

#endif // IMAGE_H
