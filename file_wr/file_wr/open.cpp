#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int fd;
	char buf[] = "let us go tcp";
	fd = open("data.txt", O_CREAT | O_WRONLY | O_TRUNC);
	if (fd == -1)
	{
		printf("open() error\n");
		return -1;
	}
	printf("file desciptor :%d\n", fd);
	if (write(fd, buf, sizeof(buf)) == -1)
	{
		printf("write() error\n");
		return -1;
	}
	close(fd);
	return 0;
}