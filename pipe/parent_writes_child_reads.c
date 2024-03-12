#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

void child(int fd[])
{
	char message[100];
	close(fd[1]);
	for (int i = 0; i < 3; i++)
	{
		read(fd[0], message, 13);
		printf("%s", message);
	}
	close(fd[0]);
}

void parent(int fd[])
{
	char *msg1 = "Hello! msg1\n";
	char *msg2 = "Hello! msg2\n";
	char *msg3 = "Hello! msg3\n";
	close(fd[0]);
	write(fd[1], msg1, strlen(msg1) + 1);
	write(fd[1], msg2, strlen(msg2) + 1);
	write(fd[1], msg3, strlen(msg3) + 1);
	close(fd[1]);
}

int main()
{
	int fd[2];
	int status = pipe(fd);
	if (status < 0)
	{
		printf("Error ocurred\n");
	}

	pid_t pid = fork();
	if (pid < 0)
	{
		printf("Error ocurred\n");
	}
	else if (pid == 0)
	{
		child(fd);
	}
	else
	{
		parent(fd);
	}
	exit(0);
}
