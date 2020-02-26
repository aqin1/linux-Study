#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>

char buf[20]="";
sem_t sem_r,sem_w;
void *pth_func(void *arg)
{
	do
	{
		sem_wait(&sem_r);
		printf("in pthread %s",buf);	
		sem_post(&sem_w);
	}
	while(strncmp(buf,"q",1));
	pthread_exit(0);
}
int main(int argc,char *argv[])
{
	pthread_t tpthread;
	sem_init(&sem_r,0,0);
	sem_init(&sem_w,0,1);

	if(!(pthread_create(&tpthread,NULL,&pth_func,NULL) == 0))
		perror("pthread_create");
	do
	{
		sem_wait(&sem_w);
		fgets(buf,20,stdin);
		sem_post(&sem_r);
	}
	while(strncmp(buf,"q",1));
	pthread_join(tpthread,NULL);
	return 0;
}
