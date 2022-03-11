/*
 * fouchette.c
 *
 *  Created on: 11 mars 2022
 *      Author: Matthias
 */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void displayInfosProcess(const char* identity){
	pid_t pid_self = getpid();
	pid_t pid_parent = getppid();
	printf("Process [%s] pid=%d ppid=%d\n", identity, pid_self, pid_parent);
}

void displayUserProcess() {
	 uid_t uid_real = getuid();
	 uid_t uid_effective = geteuid();
	 printf("UID: real=%d effective=%d\n", uid_real, uid_effective);
}

int main(int argc, char **argv) {
	printf("Common\n");
	pid_t pid_ret = fork();
	if (pid_ret==0) {
		// code du fils
		printf("I'm the child\n");
		displayInfosProcess("Luke");
		sleep(5);
		execlp("ps", "processlist", "-u", "srvadmin");
	} else {
		// code du parent
		printf("I'm your father\n");
		displayInfosProcess("Darth Vader");
		displayUserProcess();
		sleep(20);
	}
	return 0;
}

