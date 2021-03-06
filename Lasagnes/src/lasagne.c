/*
 * lasagne.c
 *
 *  Created on: 9 mars 2022
 *      Author: Matthias
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#include "planteur.h"
#include "manger.h"
#include "betterave.h"
#include "arraytool.h"
#include "macros.h"

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
	betterave_s* bett3_ptr = malloc(sizeof(betterave_s));
	if (bett3_ptr==NULL) {
		// here handle error and quit (or continue without this betterave)
		perror("Error while allocating betterave\n");
		exit(-1);
	}
	bett3_ptr->nbFeuilles = 4;
	bett3_ptr->tailleRacine = 6;
	bett3_ptr->next = &bett2; // attention danger

	betterave_s* bett4_ptr = NULL;
	if (creerBetterave(&bett4_ptr, 7, 8, bett3_ptr)==-1){
		// handle error and quit (or continue without this betterave)
		perror("Error while allocating betterave\n");
		exit(-1);
	}

	// use betteraves
	displayBetterave(bett3_ptr);
	displayBetterave(bett4_ptr);
	displayBetteraves(bett4_ptr);

	// free betterave in the heap
	free(bett3_ptr);
	free(bett4_ptr);

	// do something after free
	bett3_ptr = NULL;
}

// DG : taille definie à la compilation
// uint8_t tableau[40000000];



void test_arrays(){
	// Stack : limitée
	// uint8_t tableau[1000000];
	// variable globale à visibilité locale (static)
	static uint8_t tableau[1000000];
	printf("First cell: %d / %p\n", tableau[1], tableau);
	for (int i=0; i<sizeof(tableau); i++) {
		tableau[i] = (uint8_t) (i%255);
	}
	printf("tableau rempli\n");
}

void test_const_arrays(){
	const uint8_t * tab;
	uint8_t const * tab2;
	uint8_t * const tab3;
	uint8_t const * const tab4;
	// unsigned const const int const * const tab5 = NULL;
	unsigned const int const * const tab5 = NULL; // Warn: duplicate 'const' declaration specifier
	const unsigned int  * const tab6 = tab5;
}

void test_array_doubles(size_t sizeBetteraves1) {
	// const size_t sizeBetteraves1 = 10;
	double poidsBetteraves2[] = {1.2, 3.4};
	double poidsBetteraves1[sizeBetteraves1]; // use alloca (reserver dans stack taille dynamique)
	double* poidsBetteraves3 = malloc(sizeBetteraves1*sizeof(double));

	fillArray(poidsBetteraves1, sizeBetteraves1, 0.33);
	fillArray(poidsBetteraves3, sizeBetteraves1, 0.55);
	printf("Paramètre sizeBetteraves1: %p\n", &sizeBetteraves1);
	printf("Size poidsBetteraves1: %d, %d, %p\n",
			sizeBetteraves1, sizeof(poidsBetteraves1), poidsBetteraves1);
	printf("Size poidsBetteraves2: %d, %d, %p\n",
			2, sizeof(poidsBetteraves2), poidsBetteraves2);

	poidsBetteraves3[1]++;
	(*(poidsBetteraves3+2))+=2;
	printf("Sample: %f %f %f %f %f %f\n",
				poidsBetteraves3[0], *poidsBetteraves3,
				poidsBetteraves3[1], *(poidsBetteraves3+1),
				poidsBetteraves3[2], *(poidsBetteraves3+2));
	poidsBetteraves3 +=1;
	printf("Sample: %f %f %f %f %f %f\n",
			poidsBetteraves3[0], *poidsBetteraves3,
			poidsBetteraves3[1], *(poidsBetteraves3+1),
			poidsBetteraves3[2], *(poidsBetteraves3+2));
	free(poidsBetteraves3-1);
}

void traiterBetterave(betterave_s* betteraves, size_t n,
		void (*traitement)(betterave_s*)){
	printf("@ fun: %p, %p, %p\n", traitement, *traitement, &traitement);
	for (size_t i=0; i<n; i++) {
		// traitement(&betteraves[i]);
//		 traitement(betteraves+i);
		(*traitement)(betteraves+i);
	}
	betterave_s bet1;
}

void progFunctionalWithBetteraves() {
	betterave_s betteraves[]={
			{1,2,NULL},
			{3,4,NULL}};
	traiterBetterave(betteraves, 2, displayBetterave);
	traiterBetterave(betteraves, 2, addOneFeuille);
	traiterBetterave(betteraves, 2, &displayBetterave);
	// traiterBetterave(betteraves, 2, addOneFeuille+1); // seg fault
	traiterBetterave(betteraves, 2, *displayBetterave); // WTF !

	printf("Arithmetique pointeurs de f: %p, %p\n",
			addOneFeuille, addOneFeuille+1);

	// tableaux de taitements
	printf("Begin Tableau de traitements\n");
	void (*traitements[])(betterave_s*)={addOneFeuille, displayBetterave};
	for (int i=0; i<2; i++) {
		// traiterBetterave(betteraves, 2, traitements[i]);
		traiterBetterave(betteraves, 2, *(traitements+i));
	}
	printf("End Tableau de traitements\n");
}

void progFuncGeneric(){
	void (*traitement)(); // var pour une func à nb qq de parametres et retour void
	betterave_s bett = {3,4,NULL};

	traitement = addOneFeuille;
	traitement(&bett);  // pas de controle sur les args
	traitement(&bett, 3); // extra arg 3 is ignored
	// traitement();  // seg fault ou random

	traitement = displayBetterave;
	traitement(&bett, 3);

	traitement = addNFeuille;
	traitement(&bett, 3);

	printf("AAAAAAAAAAAAAAAAAAa\n");
	traitement(&bett); // seg fault ou random

	displayBetterave(&bett);

}

int main(int argc, char **argv) {
	// day1();
	// test_betterave_dynamique();
	// test_arrays();
//	test_arrays();
//	test_array_doubles(rand() % 1024);
//	test_array_doubles(rand() % 1024);
  tchatWithMemory();
//	progFunctionalWithBetteraves();
//	progFuncGeneric();
}


