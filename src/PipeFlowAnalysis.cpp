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
#include <chrono>

int main() {

	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	// Grab all the resistances from the CSV file at the specified path and store them to an array.
	std::string path = "./data/fake_data.csv";
	std::vector<int> resistances = getResistances(path);

	std::vector<int> voltages;
	voltages.resize(resistances.size(), 0);

	const int VOLTAGE = 120;

	for(unsigned int i = 0; i < voltages.size() - 1; i++) {
		voltages[i] = VOLTAGE;
	}

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
	printMatrix(resistanceMatrix);
	for(unsigned int i = 0; i < voltages.size(); i++) {
		float temp = getCurrent(resistanceMatrix, voltages, i);
		std::cout << "Current " << i + 1 << "  = " << temp << std::endl;
	}

	// Measures end time and computes total time in seconds and milliseconds and prints the duration.
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
	auto durationS = std::chrono::duration_cast<std::chrono::seconds>(t2 - t1);
	auto durationmS = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
	std::cout << "Program took " << durationmS.count() << " milliseconds, or " << durationS.count() << " seconds, to complete." << std::endl;

	return constants::SUCCESS;
}
