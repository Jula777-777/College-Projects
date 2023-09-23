/*
* Author:	Sean Orme (based on the work of Dr. Keith Bush)
*			UALR
*
* Date:		September 23, 2019
*
* File:		level.3.quest.cpp
*/

#include <cstdlib> 
#include <ctime> 
#include <string>
#include <iostream>
#include <vector>
#include <tuple>

#include "GUI.h"
#include "Timer.h"

#include "engine.h"
#include "Object.h"
#include"Player.h"
#include "Block.h"
#include "Enemy.h"

using namespace std;

int main(int argc, char* argv[]) {
	//Construct GUI
	GUI gui;

	auto [player1, enemies, blocks] = loadGame(
		gui,
		"./Assets/data/background.txt", 
		"./Assets/data/animation.txt",
		"./Assets/data/animation.txt");
		
	//Construct Timer
	Timer fps;

	//Initialize Termination Criteria
	bool quit = false;
	Animation::Command command{ Animation::Command::NA };

	//While the user hasn't quit
	while (quit == false)
	{
		//Start the frame timer
		fps.start();

		//GUI waits for mouse events
		if (gui.observeEvent())
		{
			//Receive Command From GUI
			command = gui.getCommand();

			//GUI transmits quit event
			if (gui.quitGame())
			{
				quit = true;
			}
		}

		//Task 3: Update Game state
		changeGameState(command, player1, enemies, gui);

		//Render Game Data
		gui.displayGameState(player1, blocks, enemies);

		//Adjust Frame Rate
		if (fps.get_ticks() < fps.frameDelay)
		{
			SDL_Delay((Uint32)fps.frameDelay - (Uint32)fps.get_ticks());
		}
	}
	//Return
	return 0;

}