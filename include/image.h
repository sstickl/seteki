#ifndef IMAGE_H
#define IMAGE_H
#include <SDL2/SDL.h>
#include <iostream>
#include "error.h"

class Sprite
{
    public:
        Sprite( const std::string, SDL_Renderer *);    //ctor
        virtual ~Sprite();   //dtor

        void incCounter() { m_Counter++; }
        void decCounter() { m_Counter--; }  //if m_Counter == 0 on this, destroy

        /** THIS SHOULD BE PRIVATE IN THE FUTURE */
        SDL_Texture *texture;   //Holds image data
    protected:

    private:
        unsigned int m_Counter; //Holds how many objects are referencing this image -- if 0, destruct
};

#endif // IMAGE_H
