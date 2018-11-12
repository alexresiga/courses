#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int i, n,p2c[2], c2p[2];
	pid_t p;
	scanf("%d", &n);
	int* v = (int*)malloc(n*sizeof(int));
	int* new = (int*)malloc(n*sizeof(int));
	for(i=0;i<n;++i) {v[i] = rand()%100;printf("%d ", v[i]);}
	printf("\n");
	pipe(p2c);
	pipe(c2p);
	p = fork();
	if (p < 0) {fprintf(stderr, "fork failed");return 1;}
	else if (p > 0)
	{//parent
		close(p2c[0]);
		write(p2c[1], v, n*sizeof(int));
		close(p2c[1]);
		wait(NULL);
		int i;
		read(c2p[0], new, n*sizeof(int));
		for(i=0;i<n;++i) printf("%d ", new[i]);
		close(c2p[0]); 
	}	
	else 
	{//child
		int* aux = (int*)malloc(n*sizeof(int));
		close(p2c[1]);
		read(p2c[0], aux, n*sizeof(int));
		int i;
		for(i=0;i<n/2;i++)
		{int elem; elem=aux[i];aux[i]=aux[n-i-1];aux[n-i-1]=elem;}
		close(c2p[0]);close(p2c[0]);
		write(c2p[1], aux, n*sizeof(int));
		close(c2p[1]);
		exit(0);
	}
	return 0;
	

}

