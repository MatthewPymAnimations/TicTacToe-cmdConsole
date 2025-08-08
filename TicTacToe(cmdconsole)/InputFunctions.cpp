#include <iostream>		// For cout, cin, getline
#include <string> 
#include <algorithm>	// For transform function
#include <sstream>		// For istringstream
#include <vector> 

using namespace std;

// Function to convert a string input into a vector of strings
vector<string> inputVector(string input) {
	istringstream iss(input);														// Create a string stream from the input string
	vector<string> result;															// Create a vector to hold the input strings
	string temp;																	// Temporary string to hold each token

	while (iss >> temp) {															// While there are still tokens in the string stream
		result.push_back(temp);														// Add the token to the vector
	}

	return result;																	// Return the vector of strings

}

