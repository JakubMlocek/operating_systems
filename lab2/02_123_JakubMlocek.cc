#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int static_memory_outofmain = 2;
int * dynamic_memory_outofmain;

int main()
{
	pid_t pid;

	dynamic_memory_outofmain = malloc(sizeof(int));
	* dynamic_memory_outofmain = 3;

	int static_memory_main = 4;
	int * dynamic_memory_main;
	dynamic_memory_main = malloc(sizeof(int));
	* dynamic_memory_main = 5;

	FILE * fptr = fopen("./test.txt", "w");

	// fork a child process
	pid = fork();

	if (pid < 0) { // error occurred
		fprintf(stderr, "Fork Failed");
		return 1;
	}
	else if (pid == 0) { // child process
		// execlp("/bin/ls", "ls", NULL);
		
		int a;
		scanf("%d", &a);
		
		printf("\nCHILD:\n");
		printf("pid = %ld\n", (long) getpid());
		printf("ppid = %ld\n", (long) getppid());

		/**/
		static_memory_outofmain += 10;
		*dynamic_memory_outofmain += 10;
		static_memory_main += 10;
		*dynamic_memory_main += 10;
		printf("static_memory_outofmain = %d\n", static_memory_outofmain);
		printf("dynamic_memory_outofmain = %d\n", *dynamic_memory_outofmain);
		printf("static_memory_main = %d\n", static_memory_main);
		printf("dynamic_memory_main = %d\n", *dynamic_memory_main);
		/**/
		/**/
		// Read contents from file
		fputs("CHILD - test put\n", fptr);
		fclose(fptr);
		/**/
	}
	else { // parent process
		// parent will wait for child to complete
		wait(NULL);

		// return 0;
		
		int b;
		scanf("%d", &b);

		printf("\nPARENT:\n");
		printf("pid = %ld\n", (long) getpid());
		printf("cpid = %ld\n", (long) pid);
		
		/**/
		printf("static_memory_outofmain = %d\n", static_memory_outofmain);
		printf("dynamic_memory_outofmain = %d\n", *dynamic_memory_outofmain);
		printf("static_memory_main = %d\n", static_memory_main);
		printf("dynamic_memory_main = %d\n", *dynamic_memory_main);
		/**/
		/**/
		// Read contents from file
		fputs("PARENTS - test put\n", fptr);
		fclose(fptr);
		/**/
	}

	return 0;
}

