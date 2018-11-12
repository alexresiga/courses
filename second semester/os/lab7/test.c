//scrieti un program care creaza un fiu care ii trimite un nume de fisier
//citit de la tastatura de parinte si fiul ii trimite inapoi dimensiunea acelui fisier

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
int main()
{
	int p2c[2], c2p[2];
	pid_t p;
	char filename[100];
	scanf("%s", filename);
	if (pipe(p2c) == -1) {fprintf(stderr, "pipe failed");return 1;}
	if (pipe(c2p) == -1) {fprintf(stderr, "pipe failed");return 1;}
	
	p = fork();
	if (p < 0) {fprintf(stderr, "fork failed");return 1;}
	if (p > 0)
	{//parent
		int size;
		close(p2c[0]);
		write(p2c[1], filename, strlen(filename)+1);
		close(p2c[1]);
		wait(NULL);
		read(c2p[0], &size, sizeof(int));
		printf("size is %d\n", size);
	}
	else
	{//child
		char name[100];
		close(c2p[0]);
		read(p2c[0], name, strlen(filename)+1);
		int fd = open(name, O_RDONLY);
		int getSize = lseek(fd, 0, SEEK_END);
		lseek(fd, 0, SEEK_SET);
		close(p2c[0]);close(c2p[0]);
		write(c2p[1], &getSize, sizeof(int));
		close(c2p[1]);
		exit(0);
	}
return 0;
}
