#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main ()
{
	pid_t p = fork();
	if (p == 0)
	{
		printf("Current ID: %d, parent ID: %d\n", getpid(), getppid());
		//printf("Current ID: %d, parent ID: %d\n", getpid(), getppid());
		char *args[] = { "./exec1", NULL };
		execvp(args[0], args);
		printf("Current ID: %d, parent ID: %d\n", getpid(), getppid());
	}
}
