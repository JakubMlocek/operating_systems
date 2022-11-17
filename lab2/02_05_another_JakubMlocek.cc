#include <stdio.h>
#include <unistd.h>

int main() {
        printf( "Hello, I'am fake another program\n") ;
        printf("%d\n", getpid());
        getchar();
	execvp("/home/zerocyber/Documents/sysopy/lab2/exec",NULL);
	return 0;
}
