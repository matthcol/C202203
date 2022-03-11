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

#define GET_STACK_SIZE(a,b) 0; \
	rl.rlim_cur = 42;

#endif

#define PRINTFD(x) printf("Valeur de " #x "= %d\n", x)
#define AFFECT(x,n,v) x ## n = v

#define CMPT1(n) n + 1
#define CMPT2(n) CMPT1(n+1) + 1
#define CMPT3(n) CMPT2(n+1) + 2
#define CMPT4(n) CMPT3(n+1) + 3
#define CMPT5(n) CMPT4(n+1) + 4
// #define CMPT6(n) CMPT5(n+1) + 5
// #define CMPT7(n) CMPT6(n+1) + 6
// #define CMPT8(n) CMPT7(n+1) + 7

void tchatWithMemory(){
	struct rlimit rl;
	int result;
	result = GET_STACK_SIZE(RLIMIT_STACK, rl);
	PRINTFD(result);
	printf("Stack size: %d\n", rl.rlim_cur);
}

void compute() {
	int lasagne1;
	int lasagne2;
	AFFECT(lasagne,1,3);
	AFFECT(lasagne,2,4);
	printf("cpt = %d\n", CMPT5(4));
}
