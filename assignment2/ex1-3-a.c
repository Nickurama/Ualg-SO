#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t pid = (fork() && fork() || fork());
	while (wait(&pid) > 0);
	system("ps");
	exit(0);
}
