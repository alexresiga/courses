#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

pthread_mutex_t word = PTHREAD_MUTEX_INITIALIZER;
int idx = 1;
char* words[100];
void* show(void* arg)
{	
	int cond = 1;
//	printf("asta e cond %d ", cond);
	while (cond) 
	{
		pthread_mutex_lock(&word);
		int a = *(int*)arg;
		printf("loop index %d si a e %d\n", idx, a);
		if (idx == a)
		{
			printf("%s ", words[a]);
			idx+=1;
			cond=0;
		}
		pthread_mutex_unlock(&word);
	}
	
	return NULL;
}

int main(int argc, char* argv[])
{
	int j, n, i;
//	printf("%s\n", "buna");
	n = argc;
	printf("%s\n", "hatz");		
	for(j=1; j< n;j++) {words[j] = argv[j];printf("%d\n", j);}	
	pthread_t threads[10];
//	printf("plm %d ", n);
	for (i=1; i<n; ++i)
	{	
//		printf("asta e idx %d ", idx);
		pthread_create(&threads[i], NULL, show, &i);
	}
	for (i=1; i<n; ++i) pthread_join(threads[i], NULL);
	printf("final idx %d\n", idx);
	return 0;
}
