/*
 * lasagne.c
 *
 *  Created on: 9 mars 2022
 *      Author: Matthias
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/resource.h>

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

void test_betterave_dynamique() {
	// betteraves in the stack
	betterave_s bett1 = {3, 5, NULL};
	betterave_s bett2 = {3, 6, &bett1};

	// betteraves in the heap
	betterave_s* bett3_ptr = (betterave_s*) malloc(sizeof(betterave_s));
	if (bett3_ptr==NULL) {
		// here handle error and quit
	}
	bett3_ptr->nbFeuilles = 4;
	bett3_ptr->tailleRacine = 6;
	bett3_ptr->next = &bett2; // attention danger

	betterave_s* bett4_ptr = NULL;
	if (creerBetterave(&bett4_ptr, 7, 8, bett3_ptr)==-1){
		// handle error and quit
	}

	// use betteraves
	displayBetterave(bett3_ptr);
	displayBetterave(bett4_ptr);
	displayBetteraves(bett4_ptr);

	// free betterave in the heap
	free(bett3_ptr);

	// do something after free
	bett3_ptr = NULL;
}

// DG : taille definie à la compilation
// uint8_t tableau[40000000];

void test_arrays(){
	// Stack : limitée
	uint8_t tableau[1000000];
	for (int i=0; i<sizeof(tableau); i++) {
		tableau[i] = (uint8_t) (i%255);
	}
	printf("tableau rempli\n");
}

void tchatWithMemory(){
	struct rlimit rl;
	int result;
	result = getrlimit(RLIMIT_STACK, &rl);
	printf("Stack size: %d\n", rl.rlim_cur);

}

int main(int argc, char **argv) {
	// day1();
	test_betterave_dynamique();
	// test_arrays();
	tchatWithMemory();
}


