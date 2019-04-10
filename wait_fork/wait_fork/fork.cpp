#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	pid_t pid,wait_pid;
	int stat;
	pid = fork();
	printf("pid %d\n", pid);
	if (pid > 0)
	{
		printf("parent %d\n", getpid());
		printf("wait_pid\n");
		while ((wait_pid = waitpid(-1, &stat, WNOHANG)) > 0)
		{
			printf("wait_pid %d\n", wait_pid);
			printf("child over\n");
		}
	}
	if (pid == 0)
	{
		printf("child %d\n", getpid());
		printf("parent %d\n", getppid());
	}
	sleep(5);
}