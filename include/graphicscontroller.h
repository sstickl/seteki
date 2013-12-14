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
        void renderTexture( SDL_Texture *, SDL_Renderer *, SDL_Rect, SDL_Rect *clip = NULL );
        void renderTexture( SDL_Texture *, SDL_Renderer *, int, int, SDL_Rect *clip = NULL );
    protected:
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        Sprite *bg;
        Sprite *ges;
};

#endif // GRAPHICSCONTROLLER_H
