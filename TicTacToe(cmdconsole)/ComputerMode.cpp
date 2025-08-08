#include "GAMEMODEENUM_H.h"		// Include the header file for the GameModeEnum enum

#include <iostream>				// For cout, cin, getline
#include <string> 
#include <algorithm>			// For transform function
#include <sstream>				// For istringstream
#include <vector> 

using namespace std;

GameModeEnum ComputerMode() {
	cout << "computermode" << endl;


	return GameModeEnum::Mainmenu;
}