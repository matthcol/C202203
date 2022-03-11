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

#define GET_STACK_SIZE(a,b) getrlimit(a, &b)

#else

struct rlimit {
	int rlim_cur;
};

#define GET_STACK_SIZE(a,b) 0

#endif

void tchatWithMemory(){
	struct rlimit rl;
	int result;
	result = GET_STACK_SIZE(RLIMIT_STACK, rl);
	printf("Stack size: %d\n", rl.rlim_cur);
}
