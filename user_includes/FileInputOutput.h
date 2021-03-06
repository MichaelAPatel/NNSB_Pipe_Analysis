//============================================================================
// Name        : FileInputOutput.h
// Author      : Michael Patel, Jeffrey McKaig, Gracen Dickens,
//			     Chase Ziegler, and Jessica Masterson
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

std::ifstream openFileR(const std::string & name);
std::ofstream openFileW(const std::string & name);
int closeFile(std::fstream & myFile);
std::vector<double> readFile(const std::string & name);

#endif /* UTILITIES_FILEINPUTOUTPUT_H_ */
