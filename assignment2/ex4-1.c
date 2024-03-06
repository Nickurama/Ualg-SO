#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	char *msg = "Hello, it's me";
	int fd[2];

	if (pipe(fd) < 0)
	{
		printf("An error ocurred creating the pipe.\n");
		return 0;
	}

	write(fd[1], msg, strlen(msg) + 1);
	close(fd[1]);



	char msg_buffer[strlen(msg) + 1];
	read(fd[0], msg_buffer, strlen(msg) + 1);
	printf("%s\n", msg_buffer);

	return 0;
}
