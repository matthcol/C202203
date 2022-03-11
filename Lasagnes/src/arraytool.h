/*
 * arraytool.h
 *
 *  Created on: 10 mars 2022
 *      Author: Matthias
 */

#ifndef ARRAYTOOL_H_
#define ARRAYTOOL_H_

#include <stddef.h>
#define N 10

// int fillArray(double array[],  size_t size, double value);
int fillArray(double* array,  size_t size, double value);

int fillMatrix(double matrix[][N], size_t size1, size_t size2, double value);

#endif /* ARRAYTOOL_H_ */
