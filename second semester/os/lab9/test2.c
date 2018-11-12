#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t par = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t impar = PTHREAD_MUTEX_INITIALIZER;

int idx = 0, v[100];

void* parF(void* arg)
{
	int a = *(int*)arg;
	pthread_mutex_lock(&par);
	if (v[a]%2 == 0) printf("par\n");
	
	pthread_mutex_unlock(&par);
	return NULL;
}

void* imparF(void* arg)
{
	int a = *(int*)arg;
	pthread_mutex_lock(&impar);
	if (v[a]%2 != 0) printf("impar\n");
	
	pthread_mutex_unlock(&impar);
	return NULL;
}

int main()
{
	pthread_t threads[2];
	int n;
	

	scanf("%d", &n);
	v[0] = n;
	pthread_create(&threads[0], NULL, parF, &idx);
	pthread_create(&threads[1], NULL, imparF, &idx);	
	while ( n != 0)
	{
		v[idx++] = n;
		
		
		scanf("%d", &n);
		
 	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);
	}
	return 0;

}
