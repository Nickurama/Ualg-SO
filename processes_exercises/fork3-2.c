#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

void forkexample()
{
	pid_t p;
	p = fork();

	if (p < 0)
	{
		perror("fork fail");
		exit(1);
	}
	else if (p == 0)
	{
		sleep(10);
		printf("Hello from child!\n");
	}
	else
		while (wait(NULL) != -1 ||  errno != ECHILD)
			printf("Waiting on child process...\n");
}

int main()
{
	forkexample();
	return 0;
}
