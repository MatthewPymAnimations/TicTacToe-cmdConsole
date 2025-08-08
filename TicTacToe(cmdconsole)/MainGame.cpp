// Copyright (c) 2025 Matthew Pym
// Licensed under the Apache License, Version 2.0
// http://www.apache.org/licenses/LICENSE-2.0




#include "THEBOARD_H.h"			// Include the header file for the printBoard function
#include "MAINMENU_H.h"			// Include the header file for the WelcomeMessage function
#include "INPUTFUNCTIONS_H.h"	// Include the header file for the inputVector function
#include "FRIENDMODE_H.h"		// Include the header file for the FriendMode function
#include "COMPUTERMODE_H.h"		// Include the header file for the ComputerMode function
#include "GAMEMODEENUM_H.h"		// Include the header file for the GameModeEnum enum

#include <iostream>		// For cout, cin, getline
#include <string> 
#include <algorithm>	// For transform function
#include <sstream>		// For istringstream
#include <vector> 

using namespace std;



// Enum to represent the game mode;
enum class GameMode {	
	Mainmenu, 
	Friend, 
	Computer, 
	Quit 

}; 


GameMode MainMenuFunction() {
	string response;

	WelcomeMessage();																						// Call the welcome message function from MainMenu_H.h


	//GET PLAYER INPUT - MAINMENU

	while (true) {

		cout << "Please enter your choice (1 or 2): ";														// Prompt the user for input

		getline(cin, response);																				// User input, read the entire line

		transform(response.begin(), response.end(), response.begin(), ::tolower);							// Convert the input to lowercase for to make comparison easier
		vector<string> responseVector = inputVector(response);												// Call the inputVector function to convert the input string into a vector of strings


		for (const string& word : responseVector) {															// Loop through each word in the response vector
			if (word == "quit" || word == "end" || word == "exit") {										// If a quit or exit is found
				return GameMode::Quit;																		// Exit the loop and return Quit mode
			}
		}

		if (response.find('1') != string::npos || response.find("friend") != string::npos) {				// If the user input is 1 or friend, `find() != string::npos` checks if the substring exists anywhere in the string; without it, you’d only detect exact matches or need manual searching.
			cout << "You chose to play against a friend!" << endl << endl;									// Print message
			return GameMode::Friend;																		// Exit the loop and proceed to the game logic
		}

		else if (response.find('2') != string::npos || response.find("computer") != string::npos) {			// If the user input is 2 or computer,
			cout << "You chose to play against the computer!" << endl << endl;								// Print message
			return ::GameMode::Computer;																	// Exit the loop and proceed to the game logic
		}

		else if (response.empty()) {																		// If the user input is empty, print error message
			cout << "You did not enter anything. Please enter 1 or 2." << endl << endl;
		}

		else {
			cout << "Invalid input. Please enter 1 or 2." << endl << endl;									// If input is not valid, print error message
		}



	}
} 



int main() {

	GameMode gameMode = GameMode::Mainmenu;			// Initialize the game mode to Mainmenu

	
	while (true) {
		switch (gameMode) {								// Switch statement to handle the game mode
		case GameMode::Mainmenu:					// If the game mode is Mainmenu
			gameMode = MainMenuFunction();					// Call the MainMenu function to get the game mode
			break;


		case GameMode::Friend:						// If the game mode is Friend

			break;									// Break out of the switch statement


		case GameMode::Computer:					// If the game mode is Computer

			break;									// Break out of the switch statement


		case GameMode::Quit:						// If the game mode is Quit
			cout << "Exiting the game, hope you had fun :)" << endl;	// Print message
			return 0;								// Exit the program

		}
	}
	


	return 0;
}