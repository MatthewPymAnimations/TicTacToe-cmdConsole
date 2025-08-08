#include "THEBOARD_H.h"			// Include the header file for the printBoard function
#include "MAINMENU_H.h"			// Include the header file for the WelcomeMessage function
#include "INPUTFUNCTIONS_H.h"	// Include the header file for the inputVector function
#include "FRIENDMODE_H.h"		// Include the header file for the FriendMode function
#include "COMPUTERMODE_H.h"		// Include the header file for the ComputerMode function
#include "GAMEMODEENUM_H.h"		// Include the header file for the GameModeEnum enum

#include <iostream>				// For cout, cin, getline
#include <string> 
#include <algorithm>			// For transform function
#include <sstream>				// For istringstream
#include <vector> 

using namespace std;


int main() {

	GameModeEnum GameMode = GameModeEnum::Mainmenu;						// Initialize the game mode to Mainmenu

	
	while (true) {
		switch (GameMode) {												// Switch statement to handle the game mode


		case GameModeEnum::Mainmenu:									// If the game mode is Mainmenu
			GameMode = MAINMENU_H::MainMenuFunction();					// Call the MainMenu function to get the game mode
			break;


		case GameModeEnum::Friend:										// If the game mode is Friend
			GameMode = FRIENDMODE_H::FriendMode();									// Call the FriendMode function to start the game
			break;														// Break out of the switch statement


		case GameModeEnum::Computer:									// If the game mode is Computer
			GameMode = COMPUTERMODE_H::ComputerMode();									// Call the ComputerMode function to start the game
			break;														// Break out of the switch statement


		case GameModeEnum::Quit:										// If the game mode is Quit
			cout << "Exiting the game, hope you had fun :)" << endl;	// Print message
			return 0;													// Exit the program


		}
	}
	







	return 0;
}