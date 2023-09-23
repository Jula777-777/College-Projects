#include <iostream>
#include <fstream>
#include <string>

#include "GUI.h"
#include "Texture.h"
#include "Object.h"
#include "Animation.h"
#include "Player.h"
#include "Enemy.h"
#include "Block.h"

using namespace std;
const Vector2D GUI::screenDimensions{ 1050, 700 };
const int GUI::numRows{ 14 };
const int GUI::numColumns{ 21 };
GUI::GUI(){

	//Start-up the GUI!
	initGUI();

	//Load in all the images and clip (if necessary)
	loadMedia();

	//Exit criteria
	quit=false;

}

GUI::~GUI(){
	cleanUp();
}

int GUI::observeEvent(){
	return(SDL_PollEvent( event ));
}

Animation::Command GUI::getCommand() {
	//Base command is "NA" for "Not Applicable"
	command = new Animation::Command;
	*command = Animation::Command::NA;

	//If a key was pressed
	if (event->type == SDL_KEYDOWN) {

		//Animate
		switch (event->key.keysym.sym)
		{
		case SDLK_UP: *command = Animation::Command::up; break;
		case SDLK_DOWN: *command = Animation::Command::down; break;
		case SDLK_LEFT: *command = Animation::Command::left; break;
		case SDLK_RIGHT: *command = Animation::Command::right; break;
		default: *command = Animation::Command::NA; break;
		}
	}

	return(*command);

}


bool GUI::quitGame(){
	return(event->type == SDL_QUIT );
}

void GUI::initGUI(){

	//Initialize all SDL subsystems
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {

		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		exit(1);
	}
	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		exit(1);
	}

	//Initialize SDL_ttf
	if (TTF_Init() == -1)
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
		exit(1);
	}

	//Construct and check window construction
	window = SDL_CreateWindow("Contra Clone",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		screenDimensions.x, screenDimensions.y, SDL_WINDOW_SHOWN);

	if (window == nullptr) {

		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		exit(1);
	}

	//Construct and check renderer construction
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr) {

		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		exit(1);

	}
	event = new SDL_Event;
}

void GUI::loadMedia(){

	//Open Enemy Sprite Sheet Forward
	enemySheetTexture = new Texture();
	enemySheetTexture->load(renderer, "./Assets/Images/opponent_sheet.png");

	//Parse enemy Sprite Sheet Forward
	enemyClips.push_back(new SDL_Rect{ 79, 16, 30, 37 });//Still Left
	enemyClips.push_back(new SDL_Rect{ 140, 16, 30, 37 });//Still Right

	for (int i = 0; i < 5; i++)
	{
		enemyClips.push_back(new SDL_Rect{ 16 + i * 25, 132, 25, 37 });//Run Left
	}


	for (int i = 0; i < 5; i++)
	{
		enemyClips.push_back(new SDL_Rect{ 143 + i * 25, 132, 25, 37 });//Run Right
	}


	for (int i = 0; i < 4; i++)
	{
		enemyClips.push_back(new SDL_Rect{ 11 + i * 22, 170, 22, 22 });//Jump Left
	}


	for (int i = 0; i < 4; i++)
	{
		enemyClips.push_back(new SDL_Rect{ 182 + i * 22, 170, 22, 22 });//Jump Right
	}

	enemyClips.push_back(new SDL_Rect{ 99, 172, 38, 20 });//Crouch Left
	enemyClips.push_back(new SDL_Rect{ 144, 172, 38, 20 });//Crouch Right

	
	//Open player Sprite Sheet Forward
	playerSheetTexture = new Texture();
	playerSheetTexture->load(renderer,"./Assets/Images/player_sheet.png");

	//Parse player Sprite Sheet Forward
	playerClips.push_back(new SDL_Rect{ 79, 16, 30, 37 });//Still Left
	playerClips.push_back(new SDL_Rect{ 140, 16, 30, 37 });//Still Right
	
	for (int i = 0; i<5; i++) 
	{
		playerClips.push_back(new SDL_Rect{ 16 + i * 25, 132, 25, 37 });//Run Left
	}

	
	for (int i = 0; i<5; i++) 
	{
		playerClips.push_back(new SDL_Rect{ 143 + i * 25, 132, 25, 37 });//Run Right
	}

	
	for (int i = 0; i<4; i++) 
	{
		playerClips.push_back(new SDL_Rect{ 11 + i * 22, 170, 22, 22 });//Jump Left
	}

	
	for (int i = 0; i<4; i++) 
	{
		playerClips.push_back(new SDL_Rect{ 182 + i * 22, 170, 22, 22 });//Jump Right
	}

	playerClips.push_back(new SDL_Rect{ 99, 172, 38, 20 });//Crouch Left
	playerClips.push_back(new SDL_Rect{ 144, 172, 38, 20 });//Crouch Right

	//Open Block Sprite Sheet
	blockSheetTexture = new Texture();
	blockSheetTexture->load(renderer,"./Assets/Images/block.png");

	guiFont = TTF_OpenFont("./Assets/fonts/impact.ttf", 40);
	if(!guiFont) printf("TTF_OpenFont: %s\n", TTF_GetError());
}

void GUI::cleanUp(){

	//Free the window
	SDL_DestroyWindow(window);
    window = nullptr;

    //Free the renderer
   	SDL_DestroyRenderer(renderer);
    renderer = nullptr;

    //Free loaded images
	playerSheetTexture->free();
    blockSheetTexture->free();
	

	TTF_CloseFont(guiFont);
    //Quit SDL Subsystems
	TTF_Quit();
   	IMG_Quit();
    SDL_Quit();

}

void GUI::displayGameState(const Player& player, const std::vector<Block>& blocks, const std::vector<Enemy> & enemies){

	//Clear screen
	SDL_SetRenderDrawColor(renderer, 51, 208, 232,255);
	SDL_RenderClear(renderer);
	//render blocks
	for (auto block : blocks)
	{
		blockSheetTexture->render(renderer, block.getPosition(), nullptr);
	}
	for (auto enemy : enemies)
	{
		enemySheetTexture->render(renderer, enemy.getPosition(), enemyClips[enemy.getSprite()]);
	}

    //Render player
	playerSheetTexture->render(renderer, player.getPosition(), playerClips[player.getSprite()]);


	string text;


	switch (*command) {
	case Animation::Command::up: text = "Jump"; break;
	case Animation::Command::down: text = "Crouch"; break;
	case Animation::Command::right: text = "Right"; break;
	case Animation::Command::left: text = "Left"; break;
	case Animation::Command::NA: text = "NA"; break;
	}

	//Render Command to Text
	SDL_Color textColor = { 255, 255, 153 };
	SDL_Texture* textSheetTexture = SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Solid(guiFont, text.c_str(), textColor));

	//Set rendering space and render to screen
	int width = 0, height = 0;
	SDL_QueryTexture(textSheetTexture, nullptr, nullptr, &width, &height);
	SDL_Rect renderQuad = { screenDimensions.x - 150, 10, width, height };

	//Render to screen
	SDL_RenderCopy(renderer, textSheetTexture, nullptr, &renderQuad);
	//-------------------------------------------------------------
	//-------------------------------------------------------------

	//Update the visible screen
	SDL_RenderPresent(renderer);


	////Update the visible screen
	//SDL_RenderPresent(renderer);
	
}

Vector2D GUI::getDimensions(const Player & player) const
{
	if (player.getSprite() < (int)playerClips.size())
	{
		return { playerClips[player.getSprite()]->w, playerClips[player.getSprite()]->h };
	}
	return { 0,0 };
}

Vector2D GUI::getDimensions(const Enemy& enemy) const
{
	if (enemy.getSprite() < (int)enemyClips.size())
	{
		return { enemyClips[enemy.getSprite()]->w, enemyClips[enemy.getSprite()]->h };
	}
	return { 0,0 };
}

Vector2D GUI::getDimensions(const Object::ObjectType type) const
{	
	switch (type)
	{
	case Object::ObjectType::block:
		return { 50,50 };
		break;
	case Object::ObjectType::enemy:
		return { enemyClips[0]->w, enemyClips[0]->h };
		break;
	default:
		return { 0,0 };
		break;
	}

}

