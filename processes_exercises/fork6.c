#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
	pid_t p = fork();
	if (p != 0)
		fork();

	printf("Hello world\n");
	return 0;
}
