/*
 * manger.C
 *
 *  Created on: 9 mars 2022
 *      Author: Matthias
 */

#include "manger.h"

// hidden dependency
#include <stdio.h>

const double PI = 3.1459;

static int fAux(int x) {
	return x+1;
}

void manger(){
	int y = fAux(3);
	printf("Je mange %d\n", y);
}

//static double threshold(double x) {
//	return sin(x) + 1 + fAux(x);
//}
