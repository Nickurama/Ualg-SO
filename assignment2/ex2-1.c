#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

void terminateOnError()
{
	printf("Fork error\n");
	exit(0);
}

void child()
{
	for (int i = 0; i < 5; i++)
		printf("Eu sou o fiho, meu pai é %d\n", getppid());
}

void parent()
{
	for (int i = 0; i < 3; i++)
		printf("Eu sou o pai, minha identificação é %d\n", getpid());
	while(wait(NULL) > 0);
}

int main()
{
	pid_t p = fork();
	
	if (p < 0)
		terminateOnError();

	if (p == 0)
		child();
	else
		parent();
}
