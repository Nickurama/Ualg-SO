#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t p1 = fork();
	int x = 0;

	if (p1 == 0)
		printf("child has x = %d", ++x);
	else
		printf("parent has x = %d", --x);


	printf("final value: %d\n", index);
	return 0;
}

