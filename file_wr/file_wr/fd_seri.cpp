#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>

int main(int argc, char *argvp[])
{
	int fd1, fd2, fd3;
	fd1 = open("test.dat", O_CREAT | O_WRONLY | O_TRUNC);   //O_TRUNC删除全部现有数据
	fd2 = socket(AF_INET, SOCK_STREAM, 0);
	fd3 = socket(AF_INET, SOCK_DGRAM, 0);

	printf("file description 1 : %d\n", fd1);
	printf("file description 2 : %d\n", fd2);
	printf("file description 3 : %d\n", fd3);
	close(fd1);
	close(fd2);
	close(fd3);
	return 0;
}