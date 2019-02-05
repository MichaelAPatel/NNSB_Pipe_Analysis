/*
 * ArrayUtilities.h
 *
 *  Created on: Feb 4, 2019
 *      Author: cs
 */

#ifndef USER_INCLUDES_ARRAYUTILITIES_H_
#define USER_INCLUDES_ARRAYUTILITIES_H_

#include <vector>

	void printMatrix(std::vector<std::vector<int>> & matrix);
	float det(std::vector<std::vector<int>> & matrix, int index);
	void getCofactor(std::vector<std::vector<int>> & matrix, std::vector<std::vector<int>> & coFactors, int p, int q, int n);
	float getCurrent(std::vector<std::vector<int>> & matrix, std::vector<int> & array, int n);


#endif /* USER_INCLUDES_ARRAYUTILITIES_H_ */
