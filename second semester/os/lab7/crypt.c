#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
void citeste(int fd, char* buffer, int size)
{
	int n=0;
	while (n<size)
		n+=read(fd, (char*)((size_t)buffer+n),size-n);
}
int main(int argc, char* argv[])
{
	char* filename = argv[1];
//	char key=0xBC;
	int p2c[2], c2p[2];
	pipe(p2c);pipe(c2p);
	int fd = open(filename, O_RDONLY);
	int size = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);	
	int n = fork();
	if (!n)
	{
		char* buffer = malloc(sizeof(char)*size);
		citeste(p2c[0], buffer, size);
		
	}
	else 
	{

		
	
		char* buffer = malloc(sizeof(char)*size);
		citeste(fd, buffer, size);
		write(p2c[1], buffer, size);
		

	}
}
