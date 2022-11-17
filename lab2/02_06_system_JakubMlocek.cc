#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
        printf( "Hello, I'am fake another program\n") ;
        printf("%d\n", getpid());
        getchar();
	system("ls -al /var/log");
	return 0;
}
