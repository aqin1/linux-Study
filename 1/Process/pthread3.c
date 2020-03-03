#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>
//#include <>

pthread_mutex_t tlock;
int value1 = 0;
int value2 = 0;
void *fpd(void *attr)
{
	do
	{
#ifdef LOCK
		pthread_mutex_lock(&tlock);
#endif
		value1++;
		value2++;
		if(value1 != value2)
			printf("value1=%d,value2=%d\n",value1,value2);
#ifdef LOCK
		pthread_mutex_unlock(&tlock);
#endif
	}
	while(1);
}

int main(int argc,char *argv[])
{
	pthread_t tpd;
	if(pthread_mutex_init(&tlock,NULL) == -1)
		perror("mutex init");
	if(pthread_create(&tpd,NULL,fpd,NULL) == -1)
		perror("pthread create");
	do
	{
#ifdef LOCK
		pthread_mutex_lock(&tlock);
#endif
		value1++;
		value2++;
		if(value1 != value2)
			printf("value1=%d,value2=%d\n",value1,value2);
#ifdef LOCK
		pthread_mutex_unlock(&tlock);
#endif
	}	
	while(1);
	return 0;
}
