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

using namespace std;

int openFileR(std::string & name) {
	ifstream myFile;
	myFile.open (name);
	if (myFile.is_open()) {
		return constants::FAILED_TO_OPEN_FILE;
	}
	return constants::SUCCESS;
}

int openFileW(std::string & name) {
	ofstream myFile;
	myFile.open (name);
	if (myFile.is_open()) {
		return constants::FAILED_TO_OPEN_FILE;
	}
	return constants::SUCCESS;

}

int closeFile(std::fstream & myFile) {
	if(myFile.is_open()) {
		myFile.close();
	}
	return constants::SUCCESS;
}

