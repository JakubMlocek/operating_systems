#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main()
{
	long long int ctr = 1;
	pid_t pid;

	while (1) {
		pid = fork();
		
		if (pid < 0) {
			printf("Fork failed!\tLiczba procesow: %lld\n", ctr);
			return 1;
		} 
		else if (pid == 0) {
			while (1)
				sleep(1);
		} 
		else {
			ctr += 1;
			printf("procesy: %lld\n", ctr);
	
		}

		usleep(1000);
	}

	return 0;
}

