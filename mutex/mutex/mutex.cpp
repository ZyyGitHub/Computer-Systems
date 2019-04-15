#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <pthread.h>
#include <unistd.h>
using namespace std;

#if 1
static void *thread_func(void * arg)
{
	printf("pthread func is run\n");
	return 0;
}
int main()
{
	vector<pthread_t> ths;
	for (int i = 0; i < 10; i++)
	{
		printf("crate %d thread\n", i);
		pthread_t tid;
		pthread_create(&tid, NULL, thread_func, NULL);
		ths.push_back(tid);
	}
	for (int i = 0; i < 10; i++)
	{
		pthread_join(ths[i], NULL);
	}
	return 0;
}
#endif

//ËÀËø
#if 0
int a;
int b;
pthread_mutex_t mutex_a;
pthread_mutex_t mutex_b;

void* another(void* arg) {
	pthread_mutex_lock(&mutex_b);
	printf("in child thread got mutex b waiting mutex a\n");
	sleep(5);
	++b;
	printf("b :%d\n", b);
	pthread_mutex_lock(&mutex_a);
	printf("in chlid thread got mutex a");
	b += a++;
	printf("a :%d\n", a);
	printf("b :%d\n", b);
	pthread_mutex_unlock(&mutex_a);
	pthread_mutex_unlock(&mutex_b);
	pthread_exit(NULL);
}
int main(int argc, char *argv[])
{
	pthread_t id;
	pthread_mutex_init(&mutex_a, NULL);
	pthread_mutex_init(&mutex_b, NULL);
	pthread_create(&id, 0, another, 0);

	pthread_mutex_lock(&mutex_a);
	printf("in child thread got mutex a waiting mutex b\n");
	sleep(5);
	++a;
	printf("a :%d\n", a);
	pthread_mutex_lock(&mutex_b);
	printf("in chlid thread got mutex b");
	a += b++;
	printf("a :%d\n", a);
	printf("b :%d\n", b);
	pthread_mutex_unlock(&mutex_b);
	pthread_mutex_unlock(&mutex_a);

	pthread_join(id, 0);
	pthread_mutex_destroy(&mutex_a);
	pthread_mutex_destroy(&mutex_b);
	return 0;
}
#endif 