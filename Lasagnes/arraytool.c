/*
 * arraytool.c
 *
 *  Created on: 10 mars 2022
 *      Author: Matthias
 */

#include "arraytool.h"

int fillArray(double array[],  size_t size, double value) {
	for (size_t i=0; i < size; i++) {
		array[i] = value;
	}
	return 0;
}
