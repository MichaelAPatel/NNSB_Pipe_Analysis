//============================================================================
// Name        : FileInputOutput
// Author      : Michael Patel & Jeffrey McKaig
// Version     : 0.1.0
// Description :
//============================================================================

#ifndef UTILITIES_FILEINPUTOUTPUT_H_
#define UTILITIES_FILEINPUTOUTPUT_H_

#include <string>
#include <fstream>
#include <fstream>
#include <vector>

#include "./constants.h"

std::ifstream openFileR(std::string & name);
std::ofstream openFileW(std::string & name);
int closeFile(std::fstream & myFile);
std::vector<int> getResistances(std::string & name);

#endif /* UTILITIES_FILEINPUTOUTPUT_H_ */
