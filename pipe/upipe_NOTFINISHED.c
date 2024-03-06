#include <unistd.h>
#include <stdio.h>
#include <string.h>
#define R 0
#define W 1

int main()
{
	int fd[2];
	char message[100];
	int nboctets;
	char *msg = "msg sent to father from child";
	pipe(fd);
	if (for() == 0)
	{
		close(fd[R]);
		write(fd[W], msg, strlen(msg) + 1);
		close(fd[W]);
	}

