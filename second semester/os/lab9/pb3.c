#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <pthread.h>
int count, x[50], sorted = 0;

pthread_mutex_t sort = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t numbers = PTHREAD_MUTEX_INITIALIZER;
void* genRandom(void* arg)
{
	int n = *(int*)arg;
	while (count < n)
	{
		pthread_mutex_lock(&numbers);
		int a = rand()%1000;
		x[count++] = a;
		pthread_mutex_unlock(&numbers);
	}
	pthread_mutex_lock(&sort);
	if (!sorted) 
	{
		sorted = 1;
		for(int i=0; i< n-1; ++i)
			for(int j = i+1; j < n; j++)
				if (x[i] > x[j]){
					int aux;
					aux = x[i];
					x[i] = x[j];
					x[j] = aux;
				}
	
	}
	pthread_mutex_unlock(&sort);
	return NULL;	
}
int main()
{	
	srand(time(NULL));
	int n;
	scanf("%d", &n);
	pthread_t th[5];
	for(int i = 0; i < 5; ++i)
	{
		pthread_create(&th[i], NULL, genRandom, &n);
	}
 	for (int i = 0; i < 5; ++i) pthread_join(th[i], NULL);

	for (int i = 0; i < n; ++i)
		printf("%d ", x[i]);
	printf("\n");
}
