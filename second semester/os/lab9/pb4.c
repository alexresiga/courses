#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t digits = PTHREAD_MUTEX_INITIALIZER;
int rev = 0, n, aux;
void* rotate(void* arg)
{
	//int n = *(int*)arg;	
	while (aux)
	{
		rev = rev*10 + aux%10;
		aux = aux/10;
	}
	
	return NULL;
}

int main()
{
	scanf("%d", &n);
	aux = n;
	pthread_t threads[5];
	for (int i = 0; i < 5; ++i)
		pthread_create(&threads[i], NULL, rotate, NULL);
	for (int i = 0 ; i < 5; ++i)
		pthread_join(threads[i], NULL);
	printf("%d\n", rev);
	return 0;
}
