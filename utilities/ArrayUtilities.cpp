//============================================================================
// Name        : ArrayUtilities.cpp
// Author      : Michael Patel, Jeffrey McKaig, Gracen Dickens,
//			     Chase Ziegler, and Jessica Masterson
// Version     : 0.1.0
// Description :
//============================================================================

#include "../user_includes/ArrayUtilities.h"
#include <vector>
#include <string>
#include <iostream>

void printMatrix(std::vector<std::vector<double>> & matrix) {
	for(unsigned int i = 0; i < matrix.size(); i++) {
		for(unsigned int j = 0; j < matrix[i].size(); j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

float det(std::vector<std::vector<double>> & matrix, int index) {
	float determinant = 0;
	int sign = 1;

	if (index == 1)
		return matrix[0][0];

	std::vector<std::vector<double>> coFactors;
	coFactors.resize(matrix.size(), std::vector<double>(matrix.size(), 0));

	for (int i = 0; i < index; i++) {
		if(matrix[0][i] == 0.0) {
			sign = -sign;
			continue;
		}
		else {
			getCofactor(matrix, coFactors, 0, i, index);
			determinant += sign * matrix[0][i] * det(coFactors, index - 1);
			sign = -sign;
		}
	}

	return determinant;
}

void getCofactor(std::vector<std::vector<double>> & matrix, std::vector<std::vector<double>> & coFactors, int p, int q, int n) {
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

float getCurrent(std::vector<std::vector<double>> & matrix, std::vector<double> & array, float detA, int n) {

	std::vector<std::vector<double>> tempMatrix;
	tempMatrix.resize(matrix.size(), std::vector<double>(matrix.size(), 0));

	for(unsigned int i = 0; i < matrix.size(); i++) {
		for(unsigned int j = 0; j < matrix[i].size(); j++) {
			tempMatrix[i][j] = matrix[i][j];
		}
	}
	for(unsigned int i = 0; i < array.size(); i++) {
		tempMatrix[i][n] = array[i];
	}

	float detAn = det(tempMatrix, matrix.size());
	float current = detAn / detA;
	return current;
}

