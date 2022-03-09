/*
 * lasagne.c
 *
 *  Created on: 9 mars 2022
 *      Author: Matthias
 */

#include <stdio.h>

#include "planteur.h"

int ajouterCouche(int nbCouches);

int ajouterCouche(int nbCouches) {
	return nbCouches + 1;
}

int main(int argc, char **argv) {
	int nbCouches = 0;
	nbCouches = ajouterCouche(nbCouches) + planter();
	printf("Lasagnes avec %d couches\n", nbCouches);
}
