#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int globalSum = 0;

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
void* sum(void* arg)
{	
	int n=*(int*)arg;
	for(int i = n+1; i <= n+100; ++i) 
	{	
		pthread_mutex_lock(&mtx);
		globalSum += i;
		pthread_mutex_unlock(&mtx);
	}
	
	return NULL;
}

int main()
{
	pthread_t th[10];
	int begin[10];
	for(int i=0; i<10;++i)
	{	
		begin[i]  = i*100;
		pthread_create(&th[i], NULL, sum, &begin[i]);  
	}
	for (int i=0; i<10; ++i) pthread_join(th[i], NULL);

	printf("%d\n",globalSum);
}
