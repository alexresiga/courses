#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int a=7, b=3, s,  p2c[2], c2p[2];
	pipe(p2c);
	pipe(c2p);
	int n=fork();
	if (!n)
	{//child
		int x[2], sum=0;
		close(p2c[1]);
		close(c2p[0]);
		read(p2c[0],&x,2*sizeof(int));
		sum=x[0]+x[1];
		write(c2p[1], &sum, sizeof(int));
		close(c2p[1]);
		close(p2c[0]);
		exit(0);
	}
	close(c2p[1]);
	close(p2c[0]);
	write(p2c[1], &a, sizeof(int));
	write(p2c[1], &b, sizeof(int));
	read(c2p[0], &s, sizeof(int));
	close(p2c[1]);
	close(c2p[0]);

	printf("%d\n",s);
return 0;
}
