/*
 * fouchette.c
 *
 *  Created on: 11 mars 2022
 *      Author: Matthias
 */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) {
	printf("Common\n");
	pid_t pid_ret = fork();
	if (pid_ret==0) {
		// code du fils
		printf("I'm the child\n");
	} else {
		// code du parent
		printf("I'm your father\n");
	}
	return 0;
}

