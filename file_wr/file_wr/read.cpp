#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
	int fd;
	char buf[30];
	fd = open("data.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open() error\n");
		return -1;
	}
	printf("file desciptor :%d\n", fd);
	if (read(fd, buf, sizeof(buf)) == -1)
	{
		printf("read() error\n");
		return -1;
	}
	printf("read file message: %s\n", buf);
	close(fd);
	return 0;
}