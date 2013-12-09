#ifndef IMAGE_H
#define IMAGE_H
#include <SDL2/SDL.h>

class image
{
    public:
        image();    //ctor
        virtual ~image();   //dtor

        unsigned int GetCounter() { return m_Counter; }
        void SetCounter(unsigned int val) { m_Counter = val; }
        SDL_Surface* Gets_data() { return s_data; }
        void Sets_data(SDL_Surface val) { *s_data = val; }

    protected:

    private:
        unsigned int m_Counter; //Holds how many objects are referencing this image -- if 0, destruct
        SDL_Surface* s_data; //Holds image data
};

#endif // IMAGE_H
