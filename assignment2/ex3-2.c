#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
void who()
{
	execlp("who", "who", (void *)NULL);
}

void ps()
{
	execlp("ps", "ps", (void *)NULL);
}

void ll()
{
	execlp("ls", "ls", "-l", (void *)NULL);
}

int main()
{
	pid_t p0;

	if (p0 = fork() == 0)
		who();
	if (p0 = fork() == 0)
		ps();
	ll();

	exit(0);
}
