/*
 * macros.c
 *
 *  Created on: 11 mars 2022
 *      Author: Matthias
 */
#include "macros.h"
#include <stdio.h>

#include "config.h"

// symbole defini par le systeme : ex __linux__


// #ifdef __linux__
// #if defined(__linux__)
#if OS==LINUX

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
