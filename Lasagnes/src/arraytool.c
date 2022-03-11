/*
 * arraytool.c
 *
 *  Created on: 10 mars 2022
 *      Author: Matthias
 */

#include "arraytool.h"

// int fillArray(double array[],  size_t size, double value) {
int fillArray(double* array,  size_t size, double value){
	for (size_t i=0; i < size; i++) {
		array[i] = value;
	}
	return 0;
}

int fillMatrix(double matrix[][N], size_t size1, size_t size2, double value){
	for (size_t i=0; i< size1; i++) {
		for (size_t j=0; j< size2; j++) {
			matrix[i][j] = value;
		}
	}
	return 0;
}
