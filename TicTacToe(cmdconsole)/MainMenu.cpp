// Copyright (c) 2025 Matthew Pym
// Licensed under the Apache License, Version 2.0
// http://www.apache.org/licenses/LICENSE-2.0


#include "MAINMENU_H.h"		// Include the header file for the WelcomeMessage function
#include "THEBOARD_H.h"			// Include the header file for the printBoard function
#include "GAMEMODEENUM_H.h"		// Include the header file for the GameModeEnum enum
#include "INPUTFUNCTIONS_H.h"

#include <iostream>				// For cout, cin, getline
#include <string> 
#include <algorithm>			// For transform function
#include <sstream>				// For istringstream
#include <vector> 


using namespace std;

void WelcomeMessage() {	// Displays the welcome message, called at the start of the game
	printBoard('X', 'O', 0, 0, 'X', 'O', 0, 'X', 'O');
	cout << "Welcome to Tic Tac Toe!" << endl << endl;

	cout << "Lets play!" << endl;
	cout << "What would you like to do?" << endl << endl;
	cout << "(1) Play against a friend? (Local)" << endl;
	cout << "or" << endl;
	cout << "(2) Play against the computer?" << endl << endl;
}

GameModeEnum MainMenuFunction() {
	string response;

	WelcomeMessage();																// Call the welcome message function from MainMenu_H.h

	while (true) {

		cout << "Please enter your choice (1 or 2): ";														// Prompt the user for input

		getline(cin, response);																				// User input, read the entire line

		transform(response.begin(), response.end(), response.begin(), ::tolower);							// Convert the input to lowercase for to make comparison easier
		vector<string> responseVector = INPUTFUNCTIONS_H::inputVector(response);							// Call the inputVector function to convert the input string into a vector of strings


		for (const string& word : responseVector) {															// Loop through each word in the response vector
			if (word == "quit" || word == "end" || word == "exit" || word == "q") {							// If a quit or exit is found
				return GameModeEnum::Quit;																	// Exit the loop and return Quit mode
			}
		}

		if (response.find('1') != string::npos || response.find("friend") != string::npos) {				// If the user input is 1 or friend, `find() != string::npos` checks if the substring exists anywhere in the string; without it, you’d only detect exact matches or need manual searching.
			cout << endl << endl << endl;									// Print message
			return GameModeEnum::Friend;																	// Exit the loop and proceed to the game logic
		}

		else if (response.find('2') != string::npos || response.find("computer") != string::npos) {			// If the user input is 2 or computer,
			cout << "You chose to play against the computer!" << endl << endl;								// Print message
			return ::GameModeEnum::Computer;																// Exit the loop and proceed to the game logic
		}

		else if (response.empty()) {																		// If the user input is empty, print error message
			cout << "You did not enter anything. Please enter 1 or 2." << endl << endl;
		}

		else {
			cout << "Invalid input. Please enter 1 or 2." << endl << endl;									// If input is not valid, print error message
		}



	}
}
