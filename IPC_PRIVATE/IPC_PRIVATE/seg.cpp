#include <stdio.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


#if 0
/* Semaphore control operation.  */
extern int semctl(int __semid, int __semnum, int __cmd, ...) __THROW;

/* Get semaphore.  */
extern int semget(key_t __key, int __nsems, int __semflg) __THROW;

/* Operate on semaphore.  */
extern int semop(int __semid, struct sembuf *__sops, size_t __nsops) __THROW;
#endif

union semun {
	int val;
	struct semid_ds* buf;
	unsigned short int* array;
	struct seminfo* __buf;
};

void pv(int sem_id, int op){
	struct sembuf sem_b;
	sem_b.sem_num = 0;
	sem_b.sem_op = op;  //op>0对信号量进行增操作，op<0对信号量的值进行减操作，op=0等待操作
	sem_b.sem_flg = SEM_UNDO;
	semop(sem_id, &sem_b, 1);  //改变信号量的值
}

int main(int argc, char* argv[])
{
	int sem_id = semget(IPC_PRIVATE, 1, 0x666); //创建一个新的信号集
	union semun sem_un;
	sem_un.val = 1;
	semctl(sem_id, 0, SETVAL, sem_un);    //对信号量进行直接的控制

	pid_t id = fork();
	if (id < 0) {
		printf("fork error\n");
		return 1;
	}
	else if (id == 0) {
		printf("child try to get binary sem\n");
		pv(sem_id, -1);
		printf("child get the sem and would relese it after 5 seconds\n");
		sleep(5);
		pv(sem_id, 1);
		exit(0);
	}
	else {
		printf("parent try to get binary sem\n");
		pv(sem_id, -1);
		printf("parent get the sem and would release it after 5 seconds\n");
		sleep(5);
		pv(sem_id, 1);
	}
	waitpid(id, NULL, 0);
	semctl(sem_id, 0, IPC_RMID, sem_un);  //删除信号
	return 0;
}