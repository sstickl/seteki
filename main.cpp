#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "include/graphicscontroller.h"
#include "include/error.h"

int main(int argc, char **argv){
	if( SDL_Init( SDL_INIT_EVERYTHING ) != 0 ){
		logSDLError( std::cout, "Could not intialize SDL");
		return 1;
	}

	if( !( IMG_Init( IMG_INIT_PNG ) ) ){ //SDL_image for PNG support
        logSDLError( std::cout, "Could not initialize SDL_image ");
        logSDLError( std::cout, IMG_GetError() );
        return 1;
	}

	GraphicsController graphicsController;

    bool quit = false;
    SDL_Event e;
    SDL_Joystick *joystick;

    if( SDL_NumJoysticks > 0 ){
        joystick = SDL_JoystickOpen( 0 );
        SDL_JoystickEventState( SDL_ENABLE );
    }
    else
        logSDLError( std::cout, "Could not initialize joystick" );

    while( !quit )
    {
        //Handle events
        while( SDL_PollEvent( &e ) )
        {
            if( e.type == SDL_QUIT )
                quit = true;
			switch( event.type ) {
				case SDL_KEYDOWN:
					switch( event.key.keysym.sym ){
						case SDLK_RIGHT: graphicsController.x=20; break;
						case SDLK_LEFT: graphicsController.x=5; break;
						case SDLK_UP: graphicsController.y=5; break;
						case SDLK_DOWN: graphicsController.y=20; break;
					}
			}
        }
        if( joystick != NULL )
        {
            switch ( SDL_JoystickGetHat( joystick, 0 ) )
            {
                case SDL_HAT_RIGHT: graphicsController.x=20; break;
                case SDL_HAT_LEFT: graphicsController.x=5; break;
                case SDL_HAT_UP: graphicsController.y=5; break;
                case SDL_HAT_DOWN: graphicsController.y=20; break;
            }
        }

        graphicsController.Draw();
    }

    SDL_JoystickClose( joystick );
    IMG_Quit(); //Quit SDL_image
	SDL_Quit();

	return 0;
}
