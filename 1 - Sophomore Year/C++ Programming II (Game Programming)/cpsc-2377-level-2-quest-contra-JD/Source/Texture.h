#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

#include "SDL.h"
#include "SDL_image.h"
#include "constants.h"

class Texture
{

    public:
        //Initializes variables
        Texture();

        //Deallocates memory
        ~Texture();

        //Loads image at specified path
        bool load(SDL_Renderer* renderer, std::string path );

        //Deallocates texture
        void free();

        //Renders texture at given point
        void render(SDL_Renderer* renderer, Vector2D position, SDL_Rect* clip = NULL );

        //Gets image dimensions
		const Vector2D getDimensions();

    private:
        //The actual hardware texture
        SDL_Texture* texture;
		//SDL_Renderer* renderer;

        //Image dimensions
        Vector2D dimension;
        

};

#endif