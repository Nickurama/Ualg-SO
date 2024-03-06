#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int fd; // fd means file descriptor
	char message[26];
	sprintf(message, "Hellow from writer [%d]\n", getpid());
	fd = open("mytube", O_WRONLY); // O_WRONLY means it can only write, not read.
	printf("here writer [%d] \n", getpid());
	if (fd != -1)
		write(fd, message, strlen(message);
	else
		printf("Sorry not available\n");
	close(fd);

	system("ps"); // system call (terminal command)
	return 0;
}

