//============================================================================
// Name        : FileInputOutput
// Author      : Michael Patel & Jeffrey McKaig
// Version     : 0.1.0
// Description :
//============================================================================

#ifndef UTILITIES_FILEINPUTOUTPUT_H_
#define UTILITIES_FILEINPUTOUTPUT_H_

#include <string>
#include "./constants.h"

namespace utilities {
int openFileR(std::string & name);
int openFileW(std::string & name);
int closeFile(std::fstream & myFile);

}
#endif /* UTILITIES_FILEINPUTOUTPUT_H_ */
