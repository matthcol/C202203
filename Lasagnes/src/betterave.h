/*
 * betterave.h
 *
 *  Created on: 9 mars 2022
 *      Author: Matthias
 */

#ifndef BETTERAVE_H_
#define BETTERAVE_H_

#include <stdint.h>

//typedef struct _betterave_s betterave_s;
//
//// attention alignment of fields
//struct _betterave_s {
//	betterave_s* next;    // 8
//	int32_t nbFeuilles;   // 4
//	uint8_t tailleRacine; // 1
//	uint8_t tailleRacine2; // 1
//	uint8_t tailleRacine3; // 1
//
//};


//struct _betterave_s {
//	uint8_t tailleRacine;
//	int32_t nbFeuilles;
//	struct _betterave_s* next;
//};
//
//typedef struct _betterave_s betterave_s;


typedef struct _betterave_s {
	uint8_t tailleRacine;
	int32_t nbFeuilles;
	struct _betterave_s* next;
} betterave_s;

typedef enum _color_e {
	C_RED=1,
	C_GREEN=2,
	C_PEAS=3
} color_e;

typedef union _choix_u {
	float x;
	int y;
} choix_u;

// functions about betteraves

// creerBetterave + gestion error
int creerBetterave(betterave_s** bett_ptr_ptr, uint8_t tailleRacine, int32_t nbFeuilles, betterave_s* next);

// displayBetterave
void displayBetterave(betterave_s* bett);
void displayBetteraves(betterave_s* bett);

void addOneFeuille(betterave_s* bett);
void addNFeuille(betterave_s* bett, int nFeuilles);


#endif /* BETTERAVE_H_ */
