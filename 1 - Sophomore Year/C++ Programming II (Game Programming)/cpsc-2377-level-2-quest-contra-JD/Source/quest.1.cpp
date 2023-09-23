/*
* Author:	Justin Dady
*			UALR
*
* Date:		February 24, 2020
*
* File:			quest.1.cpp
*
* Purpose:	The purpose of this homework is to review Programming I topics covering
*           file input/output, header/object files, random number generation seeding and
*           usage, as well as linking with the SDL graphics libraries
*/

#include <iostream> 
#include <string>

//Install Libaries and Get the GUI Running
#include "GUI.h"

//Create header and object file "engine.h"
#include "engine.h"

//Include global constants
#include "constants.h"

using namespace std;

int main(int argc, char* argv[]) {

	//Construct GUI
	GUI gui;

	//construct background
	const int maxBlocks{ 96 };
	Object blocks[maxBlocks];
	int numBlocks{ 0 };

	//Initialize the game's data source
	string gameFile("./Assets/data/background.txt");

	//Load Data from a file
	loadBackground(gameFile, numBlocks, blocks);

	//Create Player 
	Object player{ initializePlayer(gui, numBlocks, blocks) };

	//Initialize Termination Criteria
	bool quit = false;

	//While the user hasn't quit
	while (quit == false) {

		//GUI waits for mouse events
		while (gui.observeEvent()) {

			//GUI transmits quit event
			if (gui.quitGame()) {
				quit = true;
			}

		}

		//Render Game Data
		gui.displayGameState(player, numBlocks, blocks);

		//system("PAUSE");
	}

	//Return
	return 0;

}