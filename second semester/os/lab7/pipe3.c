#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int p2c[2], c2p[2];
	if (pipe(p2c)==-1)
    {
        fprintf(stderr, "Pipe Failed" );
        return 1;
    }
    if (pipe(c2p)==-1)
    {
        fprintf(stderr, "Pipe Failed" );
        return 1;
    }
	char fixed[] = "super";
	char input[100];
	pid_t p;
	scanf("%s", input);
	p = fork();
	
	if (p < 0)
	{
		fprintf(stderr, "fork failed");
		return 1;
	}
	else if (p > 0)
	{//parent
		char new[100];
		close(p2c[0]);
		write(p2c[1], input, strlen(input)+1);
		close(p2c[1]);
		wait(NULL);
		close(c2p[1]);
		read(c2p[0], new, 100);
		printf("%s\n", new);
		close(c2p[0]);
	}
	else
	{//child
		close(p2c[1]);
		char new[100];
		read(p2c[0], new, 100);
				
		int k = strlen(new);
		int i;
		for(i=0;i<strlen(fixed);++i) new[k++] = fixed[i];
		new[k] = '\0';
		
		close(p2c[0]);close(c2p[0]);
		write(c2p[1], new, strlen(new)+1);
		close(c2p[1]);
	exit(0);
	}
}
