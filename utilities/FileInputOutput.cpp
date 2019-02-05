//============================================================================
// Name        : FileInputOutput.cpp
// Author      : Michael Patel & Jeffrey McKaig
// Version     : 0.1.0
// Description :
//============================================================================

#include "../user_includes/FileInputOutput.h"
#include "../user_includes/constants.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

std::ifstream openFileR(std::string & name) {
	ifstream myFile;
	myFile.open (name);
	if (myFile.is_open()) {
		//return;
	}
	return myFile;
}

std::ofstream openFileW(std::string & name) {
	ofstream myFile;
	myFile.open (name);
	if (myFile.is_open()) {
		//return void;
	}
	return myFile;

}

int closeFile(std::fstream & myFile) {
	if(myFile.is_open()) {
		myFile.close();
	}
	return constants::SUCCESS;
}

vector<int> getResistances(std::string & name) {
	std::ifstream myFile = openFileR(name);

    vector<int> resistances;
    string line, word, temp;



        // read an entire row and
        // store it in a string variable 'line'
        getline(myFile, line);

        // used for breaking words
        std::stringstream ss(line);

        // read every column data of a row and
        // store it in a string variable, 'word'
        while(getline(ss, temp, constants::CHAR_TO_SEARCH_FOR)) {

            // add all the column data
            // of a row to a vector
            resistances.push_back(stoi(temp));
        }
        myFile.close();
        return resistances;
}

