#ifndef GRAPHICSCONTROLLER_H
#define GRAPHICSCONTROLLER_H

#include "image.h"

class GraphicsController
{
    public:
        /** Default constructor */
        GraphicsController();
        /** Default destructor */
        virtual ~GraphicsController();
        /** Rendering */
        void Draw();
    protected:
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
};

#endif // GRAPHICSCONTROLLER_H
