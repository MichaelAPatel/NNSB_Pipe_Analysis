/*
 * ArrayUtilities.cpp
 *
 *  Created on: Feb 4, 2019
 *      Author: cs
 */

#include "../user_includes/ArrayUtilities.h"
#include <vector>
#include <string>
#include <iostream>

void printArray(std::vector<std::vector<int>> & array) {
	for(unsigned int i = 0; i < array.size(); i++) {
		for(unsigned int j = 0; j < array[i].size(); j++) {
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

