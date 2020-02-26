#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int value1 = 0;
int value2 = 0;
//char *buf[20]="";
void *pth_func(void *arg)
{
	while(1)
	{
		if(value1 != value2)
			printf("in pthread %d,%d\n",value1,value2);
		sleep(1);
	}
	pthread_exit(0);
}
int main(int argc,char *argv[])
{
	pthread_t tpthread;
	if(!(pthread_create(&tpthread,NULL,&pth_func,NULL) == 0))
		perror("pthread_create");
	while(1)
	{
		value1++;
		value2++;
	}

	return 0;
}
