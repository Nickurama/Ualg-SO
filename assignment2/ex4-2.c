#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>


int child(int fd[])
{
	dup2(fd[1], 1);
	close(fd[0]);
	printf("Hello Hi");
	close(fd[1]);
}

int wc(char *str)
{
	int result = 0;
	int len = strlen(str);
	int wasLastSpace = 1;
	for (int i = 0; i < len; i++)
	{
		if (str[i] != ' ')
		{
			if (wasLastSpace)
				result++;
			wasLastSpace = 0;
		}
		else
		{
			wasLastSpace = 1;
		}
	}
	return result;
}

int parent(int fd[])
{
	char message[100];
	close(fd[1]);
	read(fd[0], message, 100 * sizeof(char));
	printf("words: %d\n", wc(message));
	close(fd[0]);
	wait(NULL);
}

int main()
{
	int fd[2];

	if (pipe(fd) < 0)
	{
		printf("An error ocurred creating the pipe.\n");
		exit(0);
	}

	pid_t p = fork();
	if(p < 0)
	{
		printf("An error ocurred forking.\n");
		exit(0);
	}

	if(p == 0)
		child(fd);
	else
		parent(fd);

	exit(0);
}
