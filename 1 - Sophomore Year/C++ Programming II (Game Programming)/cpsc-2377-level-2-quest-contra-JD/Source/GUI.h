#ifndef GUI_H
#define GUI_H

#include <string>

//GUI definitions
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include <vector>

#include "Texture.h"
#include "constants.h"

using namespace std;

class GUI
{

public:
	GUI();
	~GUI();
	int observeEvent();
	bool quitGame() const;
	void displayGameState(const Object& player, int numBlocks, const Object blocks[]);
	Vector2D getSpriteDimensions(const Object& object) const;
	

private:

	//
	// PRIVATE METHODS
	//
	void initGUI();
	void loadMedia();
	void cleanUp();

	//
	//PRIVATE MEMBERS
	//
	bool quit;

	//Window(s) to display graphics
	SDL_Window* window;

	//Hardware accelerated renderer
	SDL_Renderer* renderer;

	//The texture and clipping that will be used for Samus
	Texture* playerSheetTexture;
	std::vector<SDL_Rect*> playerClips;
	
	//The texture to be used for the blocks
	Texture* blockSheetTexture;

	//The event structure that will be used
	SDL_Event event;

};

#endif
