//============================================================================
// Name        : Pipe_Flow_Analysis.cpp
// Author      : Michael Patel & Jeffrey McKaig
// Version     : 0.1.0
// Description :
//============================================================================

#include "../user_includes/FileInputOutput.h"
#include "../user_includes/constants.h"
#include "../user_includes/ArrayUtilities.h"

#include <string>
#include <vector>
#include <iostream>

int main() {
	// Grab all the resistances from the CSV file at the specified path and store them to an array.
	std::string path = "./data/fake_data.csv";
	std::vector<int> resistances = getResistances(path);

	// Create a square matrix (array of arrays) with default value of 0 and set its size.
	std::vector<std::vector<int>> resistanceMatrix;
	resistanceMatrix.resize(resistances.size(), std::vector<int>(resistances.size(), 0));

	// Assigns the first column of the matrix.
	for(unsigned int i = 0; i < resistances.size(); i++) {
		if(i == resistances.size() - 1) {
			resistanceMatrix[i][0] = -1;
		}
		else {
			resistanceMatrix[i][0] = resistances[0];
		}
	}

	//Assigns the 2nd through 'n'th column of the matrix.
	for(unsigned int i = 0; i < resistances.size(); i++) {
		if(i == resistances.size() - 1) {
			for(unsigned int j = 1; j < resistances.size(); j++) {
					resistanceMatrix[resistanceMatrix.size() - 1][j] = 1;
			}
		}
		else {
			resistanceMatrix[i][i+1] = resistances[i + 1];
		}
	}

	// Prints they array to the console.
	printArray(resistanceMatrix);

	//todo Create Array Inverting *LOOK INTO CRAMER METHOD*
	return constants::SUCCESS;
}
