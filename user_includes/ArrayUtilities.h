//============================================================================
// Name        : ArrayUtilities.h
// Author      : Michael Patel, Jeffrey McKaig, Gracen Dickens,
//			     Chase Ziegler, and Jessica Masterson
// Version     : 0.1.0
// Description :
//============================================================================

#ifndef USER_INCLUDES_ARRAYUTILITIES_H_
#define USER_INCLUDES_ARRAYUTILITIES_H_

#include <vector>

	void printMatrix(std::vector<std::vector<double>> & matrix);
	float det(std::vector<std::vector<double>> & matrix, int index);
	void getCofactor(std::vector<std::vector<double>> & matrix, std::vector<std::vector<double>> & coFactors, int p, int q, int n);
	float getCurrent(std::vector<std::vector<double>> & matrix, std::vector<double> & array, float detA, int n);


#endif /* USER_INCLUDES_ARRAYUTILITIES_H_ */
