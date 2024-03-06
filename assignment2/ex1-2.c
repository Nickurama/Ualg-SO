#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int a = 5;
	pid_t pid;
	if (pid = fork()) // parent
	{
		wait(&pid);
		printf("Valor de a = %d\n", a);
		printf("a = %p\n", &a);
	}
	else // child
	{
		a = 10;
		printf("Valor de a = %d\n", a);
		printf("a = %p\n", &a);
	}

	exit(0);
}
