#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void error_handing(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

int main(int argc, char *argv[]) {
	int fd;
	char buf[30];
	fd = open("data.txt", O_RDONLY);
	if (fd == -1)
	{
		error_handing("open() error");
	}
	printf("file desciptor :%d\n", fd);
	if (read(fd, buf, sizeof(buf)) == -1)
		error_handing("read() error");
	printf("read file message: %s", buf);
	close(fd);
	return 0;
}