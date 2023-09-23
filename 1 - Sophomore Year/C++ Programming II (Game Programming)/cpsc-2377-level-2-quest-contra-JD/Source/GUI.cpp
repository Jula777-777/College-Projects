#include <iostream>
#include <fstream>
#include <string>

#include "GUI.h"
#include "Texture.h"
#include "constants.h"

using namespace std;

GUI::GUI(){

	//Initialize the window
	window = NULL;

    //Initialize the renderer

	//Images surfaces used in GUI
	playerSheetTexture = nullptr;
    blockSheetTexture = nullptr;

	//Start-up the GUI!
	initGUI();

	//Load in all the images and clip (if necessary)
	loadMedia();

	//Exit criteria
	quit=false;

}

GUI::~GUI()
{
	cleanUp();
}

int GUI::observeEvent()
{
	return(SDL_PollEvent( &event ));
}

bool GUI::quitGame() const
{
	return(event.type == SDL_QUIT );
}

void GUI::initGUI(){

	//Initialize all SDL subsystems
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){

		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		exit(1);
	}

	//Construct and check window construction
	window = SDL_CreateWindow("Contra Clone",
					SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED,
                    screenDimensions.x, screenDimensions.y, SDL_WINDOW_SHOWN);

	if(window==NULL){

			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			exit(1);
	}

	//Construct and check renderer construction
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL){

		printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		exit(1);

	}

}

void GUI::loadMedia(){
	//Open Block Sprite Sheet
	blockSheetTexture = new Texture();
	blockSheetTexture->load(renderer, "./Assets/Images/block.png");

	//Open player Sprite Sheet Forward
	playerSheetTexture = new Texture();
	playerSheetTexture->load(renderer,"./Assets/Images/player_sheet.png");

	//Parse player Sprite Sheet Forward		

	//Still Right
	playerClips.push_back(new SDL_Rect{ 140,16,30,37 });
	//Run Right
	for (int i = 0; i<5; i++)
	{
		playerClips.push_back(new SDL_Rect{ 143 + i * 25, 132, 25, 37 });
	}

	//Jump Right
	for (int i = 0; i<4; i++) 
	{
		playerClips.push_back(new SDL_Rect{ 182 + i * 22, 170, 22, 22 });
	}

	//Crouch Right
	playerClips.push_back(new SDL_Rect{ 144, 172, 38, 20 });
	


	
}

void GUI::cleanUp(){

	//Free the window
	SDL_DestroyWindow(window);
    window = NULL;

    //Free the renderer
   	SDL_DestroyRenderer(renderer);
    renderer = NULL;

    //Free loaded images
	playerSheetTexture->free();
    blockSheetTexture->free();


    //Quit SDL Subsystems
   	IMG_Quit();
    SDL_Quit();

}

void GUI::displayGameState(const Object & player, int numBlocks, const Object blocks[])
{

	//Clear screen
	SDL_SetRenderDrawColor(renderer, 51, 208, 232,255);
	SDL_RenderClear(renderer);

    //Render Blocks
	for(int i=0;i<numBlocks;i++){
		blockSheetTexture->render(renderer, blocks[i].position, nullptr);
	}

    //Render player
	playerSheetTexture->render(renderer, player.position, playerClips[player.sprite]);

	//Update the visible screen
	SDL_RenderPresent(renderer);
	
}

Vector2D GUI::getSpriteDimensions(const Object& object) const
{
	if (object.type == Object::Type::Player && object.sprite <= maxPlayerStates)
	{
		return { playerClips[object.sprite]->w,playerClips[object.sprite]->h };
	}
	if (object.type == Object::Type::Block)
	{
		return { 50,50 };
	}
	return Vector2D();
}


