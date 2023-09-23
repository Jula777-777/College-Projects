#ifndef GUI_H
#define GUI_H

#include <string>
#include <vector>
//GUI definitions
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

//User-defined tools
#include "Texture.h"
#include "Object.h"
#include "Animation.h"
class Player;
class Block;
class Enemy;
class GUI
{

public:
	
	const static Vector2D screenDimensions;
	const static int numRows;
	const static int numColumns;
	GUI();
	~GUI();
	int observeEvent();
	bool quitGame();
	Animation::Command getCommand();
	void displayGameState(const Player& player, const std::vector<Block>& blocks, const std::vector<Enemy>& enemies);

	Vector2D getDimensions(const Player& player) const;
	Vector2D getDimensions(const Enemy& enemy) const;
	Vector2D getDimensions(const Object::ObjectType) const;
	

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
	Animation::Command* command{ nullptr };
	bool quit;

	//Window(s) to display graphics
	SDL_Window* window{ nullptr };

	//Hardware accelerated renderer
	SDL_Renderer* renderer{ nullptr };

	//The texture and clipping that will be used for players
	Texture* playerSheetTexture{ nullptr };
	Texture* enemySheetTexture{ nullptr };
	std::vector<SDL_Rect*> playerClips;
	std::vector<SDL_Rect*> enemyClips;

	Texture* blockSheetTexture{ nullptr };
	

	
	TTF_Font* guiFont{ nullptr };

	//The event structure that will be used
	SDL_Event* event{ nullptr };

};

#endif
