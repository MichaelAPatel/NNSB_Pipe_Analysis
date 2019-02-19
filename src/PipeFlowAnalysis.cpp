//============================================================================
// Name        : Pipe_Flow_Analysis.cpp
// Author      : Michael Patel, Jeffrey McKaig, Gracen Dickens,
//			     Chase Ziegler, and Jessica Masterson
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
	// Start tracking the time.
	std::chrono::high_resolution_clock::time_point programStart = std::chrono::high_resolution_clock::now();

	// Grab all the resistances from the CSV file at the specified path and store them to an array.
	std::vector<double> resistances = readFile(constants::SIMPLE_PATH);

	// Take the voltage as the first input, and then remove it from the resistance array.
	const double VOLTAGE = resistances[0];
	resistances.erase(resistances.begin());

	// Create a voltage array and fill it.
	std::vector<double> voltages;
	voltages.resize(resistances.size(), 0);
	for(unsigned int i = 0; i < voltages.size() - 1; i++) {
		voltages[i] = VOLTAGE;
	}

	// Create a square matrix (array of arrays) with default value of 0 and set its size.
	std::vector<std::vector<double>> resistanceMatrix;
	resistanceMatrix.resize(resistances.size(), std::vector<double>(resistances.size(), 0));

	// Assigns the first column of the matrix.
	for(unsigned int i = 0; i < resistances.size(); i++) {
		if(i == resistances.size() - 1) {
			resistanceMatrix[i][0] = -1.0;
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

	// Determine all the currents.
	float detA = det(resistanceMatrix, resistanceMatrix.size());
	for(unsigned int i = 0; i < voltages.size(); i++) {
		std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
		float temp = getCurrent(resistanceMatrix, voltages, detA, i);
		std::cout << "Current " << i + 1 << "  = " << temp;
		std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
		auto durationmS = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
		float val = durationmS.count() / 1000.0;
		std::cout << " (" << val << ")" << std::endl;

	}

	// Measures end time and computes total time in seconds and milliseconds and prints the duration.
	std::chrono::high_resolution_clock::time_point programEnd = std::chrono::high_resolution_clock::now();
	auto durationS = std::chrono::duration_cast<std::chrono::milliseconds>(programEnd - programStart);
	std::cout << "Program took " << durationS.count() << " milliseconds to complete." << std::endl;

	return constants::SUCCESS;
}
