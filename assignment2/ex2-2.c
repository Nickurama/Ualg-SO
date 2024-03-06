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

void make_children(int n)
{
	for (int i = 0; i < n; i++)
	{
		pid_t p = fork();
		if (p < 0)
			terminateOnError();

		if (p == 0)
		{
			child();
			break;
		}
	}
}

void first_child()
{
	child();
	make_children(2);
	while(wait(NULL) > 0);
}

void parent()
{
	for (int i = 0; i < 3; i++)
		printf("Eu sou o pai, minha identificação é %d\n", getpid());

	make_children(3);

	while(wait(NULL) > 0);
}

int main()
{
	pid_t p = fork();
	
	if (p < 0)
		terminateOnError();

	if (p == 0)
		first_child();
	else
		parent();
}
