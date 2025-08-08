// Copyright (c) 2025 Matthew Pym
// Licensed under the Apache License, Version 2.0
// http://www.apache.org/licenses/LICENSE-2.0


#include "THEBOARD_H.h"	// Include the header file for the printBoard function

#include <iostream>		// For cout, cin, getline
#include <string> 
#include <algorithm>	// For transform function
#include <sstream>		// For istringstream
#include <vector> 
#include <array>

using namespace std;

void printBoard(char a, char b, char c, char d, char e, char f, char g, char h, char i) { // Function to print the Tic Tac Toe board

	char array[9] = { a, b, c, d, e, f, g, h, i }; // Array to hold the board values

	for (int i = 0; i < 9; i++) {	// Loop through the array and assign correct values
		if (array[i] == 0) {
			array[i] = ' ';			// Should be default, Empty space
		}
		else if (array[i] == 'X') {
			array[i] = 'X';			// Player 1's move
		}
		else if (array[i] == 'O') {
			array[i] = 'O';			// Player 2's move
		}
		else {
			array[i] = ' ';			// Any other value, something has gone wrong, default to empty space
		}

	}


	cout << array[0] << " | " << array[1] << " | " << array[2] << endl;	// Print the board
	cout << "---------" << endl;
	cout << array[3] << " | " << array[4] << " | " << array[5] << endl;
	cout << "---------" << endl;
	cout << array[6] << " | " << array[7] << " | " << array[8] << endl;
};