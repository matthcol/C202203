/*
 * betterave.c
 *
 *  Created on: 10 mars 2022
 *      Author: Matthias
 */
#include "betterave.h"

#include <stdlib.h>
#include <stdio.h>

int creerBetterave(betterave_s** bett_ptr_ptr, uint8_t tailleRacine, int32_t nbFeuilles, betterave_s* next){
	// local pointer
	betterave_s* bett_ptr = (betterave_s*) malloc(sizeof(betterave_s));
	// test si la betterave a eu la place de pousser dans le Heap
	if (bett_ptr==NULL) return -1;
	// fill the betterave
	bett_ptr->tailleRacine = tailleRacine;
	bett_ptr->nbFeuilles = nbFeuilles;
	bett_ptr->next = next;
	// return betterave pointer as an argument
	*bett_ptr_ptr = bett_ptr;
	return 0;
}

// displayBetterave
void displayBetterave(betterave_s* bett_ptr){
	printf("Bett(%d, %d, %p)\n",
			bett_ptr->tailleRacine,
			bett_ptr->nbFeuilles,
			bett_ptr->next);
}

void displayBetteraves(betterave_s* bett) {
	while(bett != NULL) {
		printf(" * ");
		displayBetterave(bett);
		bett = bett->next;
	}
}

