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

void printMatrix(std::vector<std::vector<int>> & matrix) {
	for(unsigned int i = 0; i < matrix.size(); i++) {
		for(unsigned int j = 0; j < matrix[i].size(); j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

float det(std::vector<std::vector<int>> & matrix, int index) {
	float determinant = 0;
	int sign = 1;

	if (index == 1)
		return matrix[0][0];

	std::vector<std::vector<int>> coFactors;
	coFactors.resize(matrix.size(), std::vector<int>(matrix.size(), 0));

	for (int i = 0; i < index; i++) {
		getCofactor(matrix, coFactors, 0, i, index);
		determinant += sign * matrix[0][i] * det(coFactors, index - 1);
		sign = -sign;
	}

	return determinant;
}

void getCofactor(std::vector<std::vector<int>> & matrix, std::vector<std::vector<int>> & coFactors, int p, int q, int n) {
	int i = 0, j = 0;

	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			if (row != p && col != q) {
				coFactors[i][j++] = matrix[row][col];
				if (j == n - 1) {
					j = 0;
					i++;
				}
			}
		}
	}
}

