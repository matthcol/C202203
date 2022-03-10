/*
 * lasagne.c
 *
 *  Created on: 9 mars 2022
 *      Author: Matthias
 */

#include <stdio.h>
#include <stdbool.h>

#include "planteur.h"
#include "manger.h"
#include "betterave.h"

// extern double PI;

// constante non initialisée
const double E;

int ajouterCouche(int nbCouches);

int ajouterCouche(int nbCouches) {
	return nbCouches + 1;
}

bool isGood(int nbCouches) {
	if (nbCouches==0) return false;
	return nbCouches >= 4;
}

void flottants() {
	// 0.1 (base 10) = 0.000110011001100... (base 2)
	float prix = 0.1f;
	printf("%.10f %.10f %.10f\n", prix, 2*prix, 3*prix);
}

void day1() {
	betterave_s bet = {3, 5, NULL};
	color_e color = C_GREEN;
	choix_u choix;
	int nbCouches = 0;
	nbCouches = ajouterCouche(nbCouches) + planter();
	if (threshold(3.3)) {
		nbCouches++;
	}
	printf("Lasagnes avec %d couches (%d)\n", nbCouches, isGood(nbCouches));
	flottants();
	manger();
	// call invisible function
	// printf("Invisible one ? %d\n", fAux(3));
	printf("PI = %f\n", PI);
	printf("E = %f\n", E);
	printf("Taille Betterave : %ld, %ld, %ld\n",
			sizeof(bet),
			sizeof(betterave_s),
			sizeof(color_e));
	choix.x = 3.3;
	printf("Choix : x=%f y=%d\n", choix.x, choix.y);
	choix.y = 555;
	printf("Choix : x=%f y=%d\n", choix.x, choix.y);

	struct aaa {
		uint8_t a;
		int32_t b;
		struct _betterave_s* c;
	} bett2;
	// bett2 = (struct aaa) bet;
}

int main(int argc, char **argv) {

}


