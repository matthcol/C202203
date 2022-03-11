/*
 * macros.c
 *
 *  Created on: 11 mars 2022
 *      Author: Matthias
 */
#include "macros.h"

// simulation autotools, option de compilation
#define OS linux

// symbole defini par le systeme : ex __linux__


#ifdef __linux__

#include <sys/resource.h>

void tchatWithMemory(){
	struct rlimit rl;
	int result;
	result = getrlimit(RLIMIT_STACK, &rl);
	printf("Stack size: %d\n", rl.rlim_cur);
}

#else

void tchatWithMemory(){
	printf("Stack size: UNKNOWN\n");
}

#endif
