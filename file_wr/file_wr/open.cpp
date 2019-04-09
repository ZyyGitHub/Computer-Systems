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
	char buf[] = "let us go tcp";
	fd = open("data.txt", O_CREAT | O_WRONLY | O_TRUNC);
	if (fd == -1)
	{
		error_handing("open() error");
	}
	printf("file desciptor :%d\n", fd);
	if (write(fd, buf, sizeof(buf)) == -1)
		error_handing("write() error");
	close(fd);
	return 0;
}