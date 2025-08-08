#include "GAMEMODEENUM_H.h"		// Include the header file for the GameModeEnum enum
#include "THEBOARD_H.h"			// Include the header file for the printBoard function
#include "INPUTFUNCTIONS_H.h"	// Include the header file for the inputVector function

#include <iostream>				// For cout, cin, getline
#include <string> 
#include <algorithm>			// For transform function
#include <sstream>				// For istringstream
#include <vector> 

using namespace std;

class FriendStatsClass {
	public:
		int getPlayer1Score() {
			return player1Score;	// Getter for Player 1's score
		}
		int getPlayer2Score() {
			return player2Score;	// Getter for Player 2's score
		}
		int Getdraws() {
			return draws;			// Getter for the number of draws
		}
		int getWhosTurn() {
			return whosTurn;		// Getter for whose turn it is
		}
		char getboardArray(int index) {
			return boardArray[index];	// Getter for the board array at a specific index
		}
		char getPlayer1Symbol() {
			return player1Symbol;	// Getter for Player 1's symbol
		}
		char getPlayer2Symbol() {
			return player2Symbol;	// Getter for Player 2's symbol
		}
		void SetPlayer1Score(int score) {
			player1Score = score;	// Setter for Player 1's score
		}
		void SetPlayer2Score(int score) {
			player2Score = score;	// Setter for Player 2's score
		}
		void SetDraws(int drawCount) {
			draws = drawCount;		// Setter for the number of draws
		}
		void setPlayer1Symbol(int symbol) {
			if (symbol == 1) {
				player1Symbol = 'X'; // Set Player 1's symbol to X
				player2Symbol = 'O'; // Set Player 2's symbol to O
			}
			else if (symbol == 2) {
				player1Symbol = 'O'; // Set Player 1's symbol to O
				player2Symbol = 'X'; // Set Player 2's symbol to X
			}
		}
		void setWhosTurn(int turn) {
			whosTurn = turn;		// Setter for whose turn it is
		}
		void setBoardArray(int index, char value) {
			if (index >= 0 && index < 9) {
				boardArray[index] = value;	// Setter for the board array at a specific index
			}
		}

private:
		int player1Score = 0;	// Reset Player 1's score
		int player2Score = 0;	// Reset Player 2's score
		int draws = 0;			// Reset draws
		char player1Symbol = 'X'; //1 is X, 2 is O
		char player2Symbol = 'O';
		int whosTurn = 1;		// Variable to keep track of whose turn it is, 1 for Player 1, 2 for Player 2
		char boardArray[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 }; // Array to hold the board values
};

// Create an instance of the FriendStatsClass to hold the game statistics
// Creating it outside the function allows it to maintain state across multiple calls to FriendMode
FriendStatsClass stats;		


GameModeEnum FriendMode() {

	cout << endl << endl << endl;

	printBoard(stats.getboardArray(0), stats.getboardArray(1), stats.getboardArray(2), stats.getboardArray(3), stats.getboardArray(4), stats.getboardArray(5), stats.getboardArray(6), stats.getboardArray(7), stats.getboardArray(8));
	cout << "You chose to play against a friend!" << endl << endl;




	//Get the player 1 and player 2 symbol by player input
	//Get the player 1 and player 2 symbol by player input
	//Get the player 1 and player 2 symbol by player input
	while (true) {
		string responsePlayer1Symbol;																							// Variable to hold Player 1's symbol input

		cout << "Player 1, would you like to be (X) or (O)? :";																	// Prompt Player 1 for their symbol
		getline(cin, responsePlayer1Symbol);																					// User input, read the entire line

		transform(responsePlayer1Symbol.begin(), responsePlayer1Symbol.end(), responsePlayer1Symbol.begin(), ::tolower);		// Convert the input to lowercase for to make comparison easier
		vector<string> responseVector = INPUTFUNCTIONS_H::inputVector(responsePlayer1Symbol);									// Call the inputVector function to convert the input string into a vector of strings


		for (const string& word : responseVector) {																				// Loop through each word in the response vector
			if (word == "quit" || word == "end" || word == "exit" || word == "q") {												// If a quit or exit is found
				return GameModeEnum::Quit;																						// Exit the loop and return Quit mode
			}
		}

		if (responsePlayer1Symbol.find('x') != string::npos || responsePlayer1Symbol.find("knot") != string::npos) {			// If the user input is 1 or friend, `find() != string::npos` checks if the substring exists anywhere in the string; without it, you’d only detect exact matches or need manual searching.
			stats.setPlayer1Symbol(1);																							// Set Player 1's symbol to X
			cout << "Player 1 chose X so player 2 is O" << endl;
			cout << endl << endl << endl;
			break;
		}

		else if (responsePlayer1Symbol.find('o') != string::npos || responsePlayer1Symbol.find("cross") != string::npos) {		// If the user input is 2 or computer,
			stats.setPlayer1Symbol(2);																							// Set Player 1's symbol to O
			cout << "Player 1 chose O so player 2 is X" << endl;
			cout << endl << endl << endl;
			break;

		}

		else if (responsePlayer1Symbol.empty()) {																				// If the user input is empty, print error message
			cout << "You did not enter anything. Please enter X or O." << endl << endl;
		}

		else {
			cout << "Invalid input. Please enter X or O." << endl << endl;														// If input is not valid, print error message
		}
	}



	// Print the tutorial board
	// Print the tutorial board
	// Print the tutorial board
	cout << "(1)" << " | " << "(2)" << " | " << "(3)" << endl;
	cout << "---------------" << endl;
	cout << "(4)" << " | " << "(5)" << " | " << "(6)" << endl;
	cout << "---------------" << endl;
	cout << "(7)" << " | " << "(8)" << " | " << "(9)" << endl;
	cout << endl << "Please enter the number of the square you want to play in." << endl;



	// Start the game loop
	// Start the game loop
	// Start the game loop
	while (true) {

		// Check to see if the game ended in a draw
		if (stats.getboardArray(0) != 0 && stats.getboardArray(1) != 0 && stats.getboardArray(2) != 0 &&
			stats.getboardArray(3) != 0 && stats.getboardArray(4) != 0 && stats.getboardArray(5) != 0 &&
			stats.getboardArray(6) != 0 && stats.getboardArray(7) != 0 && stats.getboardArray(8) != 0) {			// Check if the board is full
			cout << "The game is a draw!" << endl;																	// If the board is full, print draw message
			stats.SetDraws(stats.Getdraws() + 1);																	// Increment the number of draws	
			break;
		}


		// Player 1's turn
		while (stats.getWhosTurn() == 1) {
			string responsePlayerMove;


			cout << "Player 1's turn" << endl;																						// Print whose turn it is
			cout << "Player 1, please enter the number of the square you want to play in: ";										// Prompt Player 1 for their move


			getline(cin, responsePlayerMove);																						// User input, read the entire line

			transform(responsePlayerMove.begin(), responsePlayerMove.end(), responsePlayerMove.begin(), ::tolower);				// Convert the input to lowercase for to make comparison easier
			vector<string> responseVector = INPUTFUNCTIONS_H::inputVector(responsePlayerMove);										// Call the inputVector function to convert the input string into a vector of strings


			for (const string& word : responseVector) {																				// Loop through each word in the response vector
				if (word == "quit" || word == "end" || word == "exit" || word == "q") {												// If a quit or exit is found
					return GameModeEnum::Quit;																						// Exit the loop and return Quit mode
				}
			}

			if (responsePlayerMove.find_first_of("123456789") != string::npos) {
				for (char ch : responsePlayerMove) {																	// Loop through each character in the response
					if (isdigit(ch)) {																				// If the character is a digit
						int word1 = ch - '0';																		// Convert the character to an integer
						if (stats.getboardArray(word1 - 1) == 0) {													// Check if the square is already occupied
							stats.setBoardArray(word1 - 1, stats.getPlayer1Symbol());								// Set the square to Player 1's symbol
							stats.setWhosTurn(2);																	// Switch to Player 2's turn
							printBoard(stats.getboardArray(0), stats.getboardArray(1), stats.getboardArray(2), stats.getboardArray(3), stats.getboardArray(4), stats.getboardArray(5), stats.getboardArray(6), stats.getboardArray(7), stats.getboardArray(8)); // Print the board

						}
						else {
							cout << "That square is already occupied. Please choose another square." << endl;		// If the square is already occupied, print error message
							stats.setWhosTurn(1);																	// Switch back to Player 1's turn
						}
					}
				}
				break;
			}

			else if (responsePlayerMove.empty()) {																					// If the user input is empty, print error message
				cout << "You did not enter anything. Please enter X or O." << endl << endl;
			}

			else {
				cout << "Invalid input. Please enter a number of an available space." << endl << endl;								// If input is not valid, print error message
			}
		}


		// Check to see if player 1 won after their turn
		if (stats.getboardArray(0) == stats.getPlayer1Symbol() && stats.getboardArray(1) == stats.getPlayer1Symbol() && stats.getboardArray(2) == stats.getPlayer1Symbol() ||
			stats.getboardArray(3) == stats.getPlayer1Symbol() && stats.getboardArray(4) == stats.getPlayer1Symbol() && stats.getboardArray(5) == stats.getPlayer1Symbol() ||
			stats.getboardArray(6) == stats.getPlayer1Symbol() && stats.getboardArray(7) == stats.getPlayer1Symbol() && stats.getboardArray(8) == stats.getPlayer1Symbol() ||

			stats.getboardArray(0) == stats.getPlayer1Symbol() && stats.getboardArray(3) == stats.getPlayer1Symbol() && stats.getboardArray(6) == stats.getPlayer1Symbol() ||
			stats.getboardArray(1) == stats.getPlayer1Symbol() && stats.getboardArray(4) == stats.getPlayer1Symbol() && stats.getboardArray(7) == stats.getPlayer1Symbol() ||
			stats.getboardArray(2) == stats.getPlayer1Symbol() && stats.getboardArray(5) == stats.getPlayer1Symbol() && stats.getboardArray(8) == stats.getPlayer1Symbol() ||

			stats.getboardArray(0) == stats.getPlayer1Symbol() && stats.getboardArray(4) == stats.getPlayer1Symbol() && stats.getboardArray(8) == stats.getPlayer1Symbol() ||
			stats.getboardArray(2) == stats.getPlayer1Symbol() && stats.getboardArray(4) == stats.getPlayer1Symbol() && stats.getboardArray(6) == stats.getPlayer1Symbol()) {

			cout << "Player 1 Wins!!!" << endl << endl << "Well done Player 1" << endl;
			stats.SetPlayer1Score(stats.getPlayer1Score() + 1);																// Increment Player 1's score
			break;
		}

		// Check to see if the game ended in a draw
		if (stats.getboardArray(0) != 0 && stats.getboardArray(1) != 0 && stats.getboardArray(2) != 0 &&
			stats.getboardArray(3) != 0 && stats.getboardArray(4) != 0 && stats.getboardArray(5) != 0 &&
			stats.getboardArray(6) != 0 && stats.getboardArray(7) != 0 && stats.getboardArray(8) != 0) {			// Check if the board is full
			cout << "The game is a draw!" << endl;																	// If the board is full, print draw message
			stats.SetDraws(stats.Getdraws() + 1);																	// Increment the number of draws	
			break;
		}



		// Player 2's turn
		while (stats.getWhosTurn() == 2) {
			string responsePlayerMove;


			cout << "Player 2's turn" << endl;																						// Print whose turn it is
			cout << "Player 2, please enter the number of the square you want to play in: ";										// Prompt Player 2 for their move


			getline(cin, responsePlayerMove);																						// User input, read the entire line

			transform(responsePlayerMove.begin(), responsePlayerMove.end(), responsePlayerMove.begin(), ::tolower);					// Convert the input to lowercase for to make comparison easier
			vector<string> responseVector = INPUTFUNCTIONS_H::inputVector(responsePlayerMove);										// Call the inputVector function to convert the input string into a vector of strings


			for (const string& word : responseVector) {																				// Loop through each word in the response vector
				if (word == "quit" || word == "end" || word == "exit" || word == "q") {												// If a quit or exit is found
					return GameModeEnum::Quit;																						// Exit the loop and return Quit mode
				}
			}
			if (responsePlayerMove.find_first_of("123456789") != string::npos) {
				for (char ch : responsePlayerMove) {																// Loop through each character in the response
					if (isdigit(ch)) {																				// If the character is a digit
						int word1 = ch - '0';																		// Convert the character to an integer
						if (stats.getboardArray(word1 - 1) == 0) {													// Check if the square is already occupied
							stats.setBoardArray(word1 - 1, stats.getPlayer2Symbol());								// Set the square to Player 2's symbol
							stats.setWhosTurn(1);																	// Switch to Player 1's turn
							printBoard(stats.getboardArray(0), stats.getboardArray(1), stats.getboardArray(2), stats.getboardArray(3), stats.getboardArray(4), stats.getboardArray(5), stats.getboardArray(6), stats.getboardArray(7), stats.getboardArray(8)); // Print the board

						}
						else {
							cout << "That square is already occupied. Please choose another square." << endl;		// If the square is already occupied, print error message
							stats.setWhosTurn(2);																	// Switch back to Player 2's turn
						}
					}
				}
				break;
			}

			if (responsePlayerMove.empty()) {																					// If the user input is empty, print error message
				cout << "You did not enter anything. Please enter X or O." << endl << endl;
			}

			else {
				cout << "Invalid input. Please enter a number of an available space." << endl << endl;								// If input is not valid, print error message
			}
		}



		// // Check to see if player 2 won after their turn
		if (stats.getboardArray(0) == stats.getPlayer2Symbol() && stats.getboardArray(1) == stats.getPlayer2Symbol() && stats.getboardArray(2) == stats.getPlayer2Symbol() ||
			stats.getboardArray(3) == stats.getPlayer2Symbol() && stats.getboardArray(4) == stats.getPlayer2Symbol() && stats.getboardArray(5) == stats.getPlayer2Symbol() ||
			stats.getboardArray(6) == stats.getPlayer2Symbol() && stats.getboardArray(7) == stats.getPlayer2Symbol() && stats.getboardArray(8) == stats.getPlayer2Symbol() ||

			stats.getboardArray(0) == stats.getPlayer2Symbol() && stats.getboardArray(3) == stats.getPlayer2Symbol() && stats.getboardArray(6) == stats.getPlayer2Symbol() ||
			stats.getboardArray(1) == stats.getPlayer2Symbol() && stats.getboardArray(4) == stats.getPlayer2Symbol() && stats.getboardArray(7) == stats.getPlayer2Symbol() ||
			stats.getboardArray(2) == stats.getPlayer2Symbol() && stats.getboardArray(5) == stats.getPlayer2Symbol() && stats.getboardArray(8) == stats.getPlayer2Symbol() ||

			stats.getboardArray(0) == stats.getPlayer2Symbol() && stats.getboardArray(4) == stats.getPlayer2Symbol() && stats.getboardArray(8) == stats.getPlayer2Symbol() ||
			stats.getboardArray(2) == stats.getPlayer2Symbol() && stats.getboardArray(4) == stats.getPlayer2Symbol() && stats.getboardArray(6) == stats.getPlayer2Symbol()) {

			cout << "Player 2 Wins!!!" << endl << endl << endl << "Well done Player 2" << endl;
			stats.SetPlayer2Score(stats.getPlayer2Score() + 1);                                                              // Increment Player 2's score
			break;
		}



	}



	// End of the game, print the scores and ask if the players want to play again
	// End of the game, print the scores and ask if the players want to play again
	// End of the game, print the scores and ask if the players want to play again
	while (true) {
		string responsePlayAgain;

		cout << "Player 1's wins:" << stats.getPlayer1Score() << endl << "Player 2's wins:" << stats.getPlayer2Score() << endl << "Draws:" << stats.Getdraws() << endl << "Would you like to play again? (Yes/No): ";																		// Prompt the user for input

		getline(cin, responsePlayAgain);																						// User input, read the entire line

		transform(responsePlayAgain.begin(), responsePlayAgain.end(), responsePlayAgain.begin(), ::tolower);					// Convert the input to lowercase for to make comparison easier
		vector<string> responseVector = INPUTFUNCTIONS_H::inputVector(responsePlayAgain);										// Call the inputVector function to convert the input string into a vector of strings

		for (const string& word : responseVector) {																				// Loop through each word in the response vector
			if (word == "quit" || word == "end" || word == "exit" || word == "q") {												// If a quit or exit is found
				return GameModeEnum::Quit;																						// Exit the loop and return Quit mode
			}
		}

		if (responsePlayAgain.find("yes") != string::npos || responsePlayAgain.find("y") != string::npos) {						// If the user input contains "yes" or "y"
			cout << endl << endl << endl;																						// Print message
			stats.setWhosTurn(1);																								// Reset whose turn it is to Player 1
			for (int i = 0; i < 9; i++) {																						// Reset the board array
				stats.setBoardArray(i, 0);
			}
			return GameModeEnum::Friend;																						// Continue the loop to start a new game
		}
		else if (responsePlayAgain.find("no") != string::npos || responsePlayAgain.find("n") != string::npos) {					// If the user input contains "no" or "n"
			cout << endl << endl << "Back to the Main Menu!" << endl;															// Print message
			stats.setWhosTurn(1);																								// Reset whose turn it is to Player 1
			for (int i = 0; i < 9; i++) {																						// Reset the board array
				stats.setBoardArray(i, 0);
			}
			return GameModeEnum::Mainmenu;																						// Exit the loop and return Mainmenu mode
		}
		else if (responsePlayAgain.empty()) {																					// If the user input is empty, print error message
			cout << "You did not enter anything. Please enter yes or no." << endl << endl;
		}
		else {
			cout << "Invalid input. Please enter yes or no." << endl << endl;													// If input is not valid, print error message
		}
	}

	return GameModeEnum::Mainmenu;
}