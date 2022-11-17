#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void signalHandler( int signum ){
	printf("Signal: %i  recieved\n",signum);
	if (signum == SIGINT){
		printf("SIGINT");
		exit(signum);
	}
}

int main(){
	for (int i = 1; i <= 64; i++) {
		if (signal(i, signalHandler) == SIG_ERR)
			printf("sig %d nie da się złapać\n", i);
	}
	signal(SIGINT, signalHandler);
	signal(SIGSEGV, signalHandler);
	signal(SIGTERM, signalHandler);
	signal(SIGILL, signalHandler);
	signal(SIGABRT, signalHandler);
	signal(SIGFPE, signalHandler);
	
	int a;
	scanf("%i",a);
}	
