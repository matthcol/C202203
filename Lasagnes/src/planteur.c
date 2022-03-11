/*
 * planteur.c
 *
 *  Created on: 9 mars 2022
 *      Author: Matthias
 */

#include "planteur.h"

// extern double PI;

static int fAux(int x) {
	return x+1;
}

int planter() {
	return fAux(5);
}

double threshold(double x) {
	// PI+=1.3333E-5;  // interdit si const
	return sin(x+2*PI) + 1 + fAux(x);
}

